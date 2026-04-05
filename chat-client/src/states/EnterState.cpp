#include "states/EnterState.hpp"
#include "states/LoginState.hpp"
#include "states/RegistrationState.hpp"
#include "states/ExitState.hpp"
#include "states/State.hpp"

#include <memory>
#include <iostream>
#include <string>
#include <clients/Client.hpp>
#include <fsms/StateMachine.hpp>

namespace ChatClient
{
    ChatClient::EnterState::EnterState(
        ChatEngine::StateMachine& stateMachine, 
        ChatEngine::Client& client
    ):
        State(stateMachine),
        m_client(client)
    {

    }

    void EnterState::handle()
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
                m_stateMachine.moveToState<LoginState>();
                return;
            case '2':
                m_stateMachine.moveToState<RegistrationState>();
                return;
            case '3': 
                m_stateMachine.moveToState<ExitState>();
                return;
            default: 
                std::cout << "Invalid selection, please try again.\n";
                break;
            }
        }
    }
}