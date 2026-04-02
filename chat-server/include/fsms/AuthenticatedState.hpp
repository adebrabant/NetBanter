#pragma once

#include "fsms/SessionState.hpp"
#include "fsms/SessionStateMachine.hpp"
#include "clients/Client.hpp"

namespace ChatServer
{
	class AuthenticatedState : public SessionState
	{
	public:
		AuthenticatedState(
			ChatServer::SessionStateMachine& stateMachine,
			ChatEngine::Client* client
		);
		void process() override;

	private:
		ChatServer::SessionStateMachine& m_stateMachine;
		ChatEngine::Client* m_client;
	};
}