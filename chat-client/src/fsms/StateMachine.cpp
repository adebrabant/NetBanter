#include "fsms/StateMachine.hpp"
#include "fsms/State.hpp"
#include <utility>

namespace ChatClient
{
	void StateMachine::run()
	{
		while (m_currentState)
		{
			m_currentState = std::move(m_currentState->onProcess());
		}
	}
}