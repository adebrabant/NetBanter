#include "states/MainMenuState.hpp"
#include "states/ChatState.hpp"
#include "clients/Client.hpp"
#include "states/State.hpp"
#include "fsms/StateMachine.hpp"

namespace ChatClient
{
	MainMenuState::MainMenuState(
		ChatEngine::StateMachine& stateMachine, 
		ChatEngine::Client& client
	):
		State(stateMachine),
		m_client(client)
	{

	}

	void MainMenuState::handle()
	{
		m_stateMachine.moveToState<ChatState>();
	}
}