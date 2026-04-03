#pragma once

#include "states/State.hpp"
#include "clients/Client.hpp"
#include "fsms/StateMachine.hpp"

namespace ChatClient
{
	class LoginState : public ChatEngine::State
	{
	public:
		LoginState(ChatEngine::StateMachine& stateMachine, ChatEngine::Client& client);
		void handle() override;

	private:
		ChatEngine::Client& m_client;
	};
}