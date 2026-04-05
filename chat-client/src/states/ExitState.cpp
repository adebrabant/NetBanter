#include "states/ExitState.hpp"
#include "states/State.hpp"
#include "fsms/StateMachine.hpp"

namespace ChatClient
{
	ExitState::ExitState(ChatEngine::StateMachine& stateMachine) :
		State(stateMachine)
	{

	}

	void ExitState::handle()
	{
		m_stateMachine.exit();
	}
}