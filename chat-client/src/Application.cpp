#include "Application.hpp"
#include "networks/TcpSocket.hpp"
#include "states/EnterState.hpp"
#include "states/LoginState.hpp"
#include "states/RegistrationState.hpp"
#include "states/MainMenuState.hpp"
#include "states/ChatState.hpp"
#include "states/ExitState.hpp"

#include <memory>
#include "clients/Client.hpp"
#include <utility>

namespace ChatClient
{
    Application::Application() :
        m_network(),
        m_stateMachine()
    {

    }

    int Application::run()
	{
        setup();
        m_stateMachine.moveToState<EnterState>();
        m_stateMachine.run();
        return 0;
	}

    void Application::setup()
    {
        ChatEngine::TcpSocket socket;
        socket.connectTo("127.0.0.1", 12345);
        m_client = std::make_unique<ChatEngine::Client>(std::move(socket));
        m_stateMachine.addState<EnterState>(m_stateMachine, *m_client);
        m_stateMachine.addState<LoginState>(m_stateMachine, *m_client);
        m_stateMachine.addState<RegistrationState>(m_stateMachine, *m_client);
        m_stateMachine.addState<MainMenuState>(m_stateMachine, *m_client);
        m_stateMachine.addState<ChatState>(m_stateMachine, *m_client);
        m_stateMachine.addState<ExitState>(m_stateMachine);
    }
}