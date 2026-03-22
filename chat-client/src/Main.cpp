#include "networks/TcpSocket.hpp"
#include "networks/NetworkSystem.hpp"
#include "clients/Client.hpp"
#include <thread>
#include <iostream>
#include <utility>
#include <string>
#include <stdexcept>
#include <conio.h>

// ToDo: Clean up all this into a state machine
int main()
{
    ChatEngine::NetworkSystem network;
    ChatEngine::TcpSocket socket;
    socket.connectTo("127.0.0.1", 12345);
    std::string username;
    std::string password;
    std::string response;

    do 
    {
        std::cout << "Enter Username: ";
        std::getline(std::cin, username);

        std::cout << "Enter password: ";
        std::getline(std::cin, password);

        std::string loginCommand = "LOGIN:" + username + ":" + password;
        socket.send(loginCommand);

        char buffer[1024] = { 0 };
        int bytes = socket.receive(buffer, 1024);
        response = std::string(buffer, bytes);

        if (response != "LOGIN_SUCCESS") {
            std::cout << "Login failed. Please try again.\n";
        }

    } while (response != "LOGIN_SUCCESS");

    std::cout << "Login successful!\n";

    ChatEngine::Client client(std::move(socket), username);

    std::thread receiveThread([&client]() {
        while (true) {
            try {
                std::string message = client.receiveMessage();
                if (!message.empty())
                    std::cout << message << std::endl;
            }
            catch (const std::runtime_error&) {
                std::cout << "Disconnected from server" << std::endl;
                break;
            }
        }
        });

    std::cout << "Connected! Type messages and press Enter:" << std::endl;

    while (true) 
    {
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) 
            continue;

        if (!client.sendMessage(input))
            std::cout << "Failed to send message!" << std::endl;
    }

    receiveThread.join();
    return 0;
}