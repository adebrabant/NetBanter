#include "fsms/EnterState.hpp"
#include "fsms/LoginState.hpp"
#include "fsms/RegistrationState.hpp"
#include "fsms/ExitState.hpp"
#include "fsms/State.hpp"

#include <memory>
#include <iostream>
#include <string>


namespace ChatClient
{
	EnterState::EnterState(ChatEngine::TcpSocket& tcpSocket) :
		m_tcpSocket(tcpSocket)
	{

	}

    std::unique_ptr<State> EnterState::onProcess()
    {
        std::string userInput;

        while (true)
        {
            std::cout << "Welcome to NetBanter:\n"
                << " 1) Login\n"
                << " 2) Register\n"
                << " 3) Exit\n"
                << "Select an option: ";

            std::getline(std::cin, userInput);

            if (userInput.empty())
                continue;

            switch (userInput[0])
            {
            case '1': 
                return std::make_unique<LoginState>(m_tcpSocket);

            case '2': 
                return std::make_unique<RegistrationState>(m_tcpSocket);

            case '3': 
                return std::make_unique<ExitState>();

            default: 
                std::cout << "Invalid selection, please try again.\n";
                break;
            }
        }
    }
}