#include "fsms/SessionStateMachine.hpp"
#include "fsms/SessionState.hpp"

namespace ChatServer
{
	SessionStateMachine::SessionStateMachine() :
		m_currentState(nullptr)
	{

	}

	void SessionStateMachine::run()
	{
		while (m_currentState)
		{
			m_currentState->process();
		}
	}
}