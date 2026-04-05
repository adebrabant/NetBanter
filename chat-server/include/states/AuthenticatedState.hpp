#pragma once

#include "states/State.hpp"
#include "fsms/StateMachine.hpp"
#include "clients/Client.hpp"

namespace ChatServer
{
	class AuthenticatedState : public ChatEngine::State
	{
	public:
		AuthenticatedState(
			ChatEngine::StateMachine& stateMachine,
			ChatEngine::Client* client
		);
		void handle() override;

	private:
		ChatEngine::Client* m_client;
	};
}