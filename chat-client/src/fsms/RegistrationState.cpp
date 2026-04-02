#include "fsms/RegistrationState.hpp"
#include "fsms/MainMenuState.hpp"
#include "networks/TcpSocket.hpp"
#include "fsms/State.hpp"
#include "clients/Client.hpp"
#include <memory>
#include <iostream>
#include <string>
#include <utility>

namespace ChatClient
{
	RegistrationState::RegistrationState(ChatEngine::TcpSocket& tcpSocket) :
		m_tcpSocket(tcpSocket)
	{

	}

	std::unique_ptr<State> RegistrationState::onProcess()
	{
        std::string response;
        std::string username;
        std::string password;

        do
        {
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);

            while (true)
            {
                std::string repassword;
                std::cout << "Enter password: ";
                std::getline(std::cin, password);

                std::cout << "Re-enter password: ";
                std::getline(std::cin, repassword);

                if (password == repassword)
                    break;

                std::cout << "Passwords do not match, please re-enter!" << std::endl;
            }

            std::string registrationCommand = "REGISTER:" + username + ":" + password;
            m_tcpSocket.send(registrationCommand);

            char buffer[1024] = { 0 };
            int bytes = m_tcpSocket.receive(buffer, sizeof(buffer));
            response = std::string(buffer, bytes);

            if (response != "REGISTER_SUCCESS") 
            {
                std::cout << "Registration failed. Please try again.\n";
            }

        } while (response != "REGISTER_SUCCESS");

        return std::make_unique<MainMenuState>(
            std::make_unique<ChatEngine::Client>(std::move(m_tcpSocket), username)
        );
	}
}