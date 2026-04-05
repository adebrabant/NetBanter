#include "states/RegistrationState.hpp"
#include "states/MainMenuState.hpp"
#include "states/State.hpp"
#include "clients/Client.hpp"
#include "fsms/StateMachine.hpp"

#include <iostream>
#include <string>

namespace ChatClient
{
    RegistrationState::RegistrationState(
        ChatEngine::StateMachine& stateMachine, 
        ChatEngine::Client& client
    ) :
        State(stateMachine),
        m_client(client)
    {

    }

    void RegistrationState::handle()
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
            m_client.sendMessage(registrationCommand);

            char buffer[1024] = { 0 };
            std::string response = m_client.receiveMessage();

            if (response != "REGISTER_SUCCESS") 
            {
                std::cout << "Registration failed. Please try again.\n";
            }

        } while (response != "REGISTER_SUCCESS");

        m_client.setUsername(username);
        m_stateMachine.moveToState<MainMenuState>();
	}
}