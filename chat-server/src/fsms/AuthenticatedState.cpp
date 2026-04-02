#pragma once

#include "fsms/AuthenticatedState.hpp"
#include "fsms/SessionStateMachine.hpp"

#include <iostream>

namespace ChatServer
{
	AuthenticatedState::AuthenticatedState(
		ChatServer::SessionStateMachine& stateMachine, 
		ChatEngine::Client* client
	):
		m_stateMachine(stateMachine),
		m_client(client)
	{

	}

	void AuthenticatedState::process()
	{
		std::cout << "We hit the Auth state";
		while (true)
		{

		}
	}
}