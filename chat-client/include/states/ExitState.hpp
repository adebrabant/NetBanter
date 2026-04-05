#pragma once

#include "states/State.hpp"
#include "fsms/StateMachine.hpp"

namespace ChatClient
{
	class ExitState : public ChatEngine::State
	{
	public:
		ExitState(ChatEngine::StateMachine& stateMachine);
		void handle() override;
	};
}