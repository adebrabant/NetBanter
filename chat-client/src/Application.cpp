#include "Application.hpp"
#include "networks/TcpSocket.hpp"
#include "fsms/EnterState.hpp"

namespace ChatClient
{
    Application::Application() :
        m_network(),
        m_tcpSocket(),
        m_stateMachine()
    {

    }

    int Application::run()
	{
        m_tcpSocket.connectTo("127.0.0.1", 12345);
        m_stateMachine.moveToState<EnterState>(m_tcpSocket);
        m_stateMachine.run();
        return 0;
	}
}