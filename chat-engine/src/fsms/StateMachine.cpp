#include "fsms/StateMachine.hpp"
#include "states/State.hpp"

namespace ChatEngine
{
	StateMachine::StateMachine() :
		m_currentState(nullptr)
	{

	}

	void StateMachine::run()
	{
		while (m_currentState)
		{
			m_currentState->handle();
		}
	}

	void StateMachine::exit()
	{
		m_currentState = nullptr;
	}
}