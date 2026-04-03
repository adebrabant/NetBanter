#pragma once

#include "states/AuthenticatedState.hpp"
#include "fsms/StateMachine.hpp"
#include "clients/Client.hpp"
#include "states/State.hpp"

#include <iostream>

namespace ChatServer
{
	AuthenticatedState::AuthenticatedState(
		ChatEngine::StateMachine& stateMachine, 
		ChatEngine::Client* client
	):
		State(stateMachine),
		m_client(client)
	{

	}

	void AuthenticatedState::handle()
	{
		std::cout << "We hit the Auth state";
		while (true)
		{

		}
	}
}