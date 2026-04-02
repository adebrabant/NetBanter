#include "fsms/LoginState.hpp"
#include "fsms/MainMenuState.hpp"
#include "fsms/State.hpp"
#include "clients/Client.hpp"
#include "networks/TcpSocket.hpp"

#include <memory>
#include <iostream>
#include <string>
#include <utility>

namespace ChatClient
{
	LoginState::LoginState(ChatEngine::TcpSocket& tcpSocket) :
		m_tcpSocket(tcpSocket)
	{

	}

	std::unique_ptr<State> LoginState::onProcess()
	{
        std::string response;
        std::string username;
        std::string password;

        do
        {
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);

            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            std::string loginCommand = "LOGIN:" + username + ":" + password;
            m_tcpSocket.send(loginCommand);

            char buffer[1024] = { 0 };
            int bytes = m_tcpSocket.receive(buffer, sizeof(buffer));
            response = std::string(buffer, bytes);

            if (response != "LOGIN_SUCCESS") {
                std::cout << "Login failed. Please try again.\n";
            }

        } while (response != "LOGIN_SUCCESS");

        return std::make_unique<MainMenuState>(
            std::make_unique<ChatEngine::Client>(std::move(m_tcpSocket), username)
        );
	}
}