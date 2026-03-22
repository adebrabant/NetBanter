#include "networks/NetworkSystem.hpp"
#include "networks/TcpServer.hpp"
#include "networks/TcpSocket.hpp"
#include "clients/Client.hpp"
#include "clients/ClientManager.hpp"
#include "messages/Messenger.hpp"
#include "messages/Message.hpp"
#include "messages/DeliveryResult.hpp"
#include "authentications/Authenticator.hpp"
#include "authentications/AuthResult.hpp"
#include "users/UserRepository.hpp"

#include <thread>
#include <chrono>
#include <iostream>
#include <ctime>
#include <string>
#include <memory>
#include <utility>
#include <stdexcept>
#include <corecrt.h>

int main()
{
    // ToDo: Clean up all this into a state machine
    ChatEngine::NetworkSystem network;
    ChatEngine::TcpServer server(12345);
    ChatEngine::ClientManager clientManager;
    ChatEngine::Messenger messenger;
    ChatEngine::UserRepository userRepository;
    ChatEngine::Authenticator authenticator(userRepository);

    std::cout << "Server started on port 12345...." << std::endl;

    // Fake existing user for now
    authenticator.registerUser("user1", "password");

    while (true)
    {
        ChatEngine::TcpSocket newSocket = server.acceptClient();

        std::thread([socket = std::move(newSocket), &authenticator, &clientManager, &messenger]() mutable {
            ChatEngine::Client* clientPtr = nullptr;
            bool authenticated = false;
            std::string username;

            while (!authenticated)
            {
                char buffer[1024] = { 0 };
                int bytes = socket.receive(buffer, 1024);
                if (bytes <= 0)
                    return;

                std::string message(buffer, bytes);
                if (message.rfind("LOGIN:", 0) != 0)
                    continue;

                auto sep = message.find(':', 6);
                if (sep == std::string::npos)
                    continue;

                username = message.substr(6, sep - 6);
                std::string password = message.substr(sep + 1);
                auto result = authenticator.loginUser(username, password);
                if (result.isSuccessful())
                {
                    socket.send("LOGIN_SUCCESS");
                    auto client = std::make_unique<ChatEngine::Client>(std::move(socket), username);
                    clientPtr = client.get();
                    clientManager.add(std::move(client));
                    authenticated = true;
                    std::cout << "Client logged in: " << username << std::endl;
                }
                else
                {
                    socket.send("LOGIN_FAILED: " + result.getMessage());
                }
            }

            while (authenticated)
            {
                try
                {
                    std::string rawMessage = clientPtr->receiveMessage();
                    if (rawMessage.empty())
                        continue;

                    const std::string sender = clientPtr->getUsername();
                    time_t timestamp(0);
                    ChatEngine::Message message(sender, sender, rawMessage, timestamp);

                    for (auto recipient : clientManager.findAll())
                    {
                        messenger.deliver(message, recipient);
                    }
                }
                catch (...)
                {
                    std::cout << "Client disconnected: " <<
                        clientPtr->getUsername() << std::endl;
                    clientManager.remove(clientPtr->getSocket());

                    break;
                }
            }
        }).detach();
    }

    return 0;
}