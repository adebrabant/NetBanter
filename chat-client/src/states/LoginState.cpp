#include "states/LoginState.hpp"
#include "states/MainMenuState.hpp"
#include "states/State.hpp"
#include "clients/Client.hpp"
#include "fsms/StateMachine.hpp"

#include <iostream>
#include <string>

namespace ChatClient
{
    ChatClient::LoginState::LoginState(
        ChatEngine::StateMachine& stateMachine, 
        ChatEngine::Client& client
    ) :
        State(stateMachine),
        m_client(client)
    {

    }

	void LoginState::handle()
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
            m_client.sendMessage(loginCommand);

            std::string response = m_client.receiveMessage();

            if (response != "LOGIN_SUCCESS") {
                std::cout << "Login failed. Please try again.\n";
            }

        } while (response != "LOGIN_SUCCESS");

        m_client.setUsername(username);
        m_stateMachine.moveToState<MainMenuState>();
	}
}