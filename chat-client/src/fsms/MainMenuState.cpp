#include "fsms/MainMenuState.hpp"
#include "fsms/ChatState.hpp"
#include "clients/Client.hpp"
#include "fsms/State.hpp"
#include <memory>
#include <utility>

namespace ChatClient
{
	MainMenuState::MainMenuState(std::unique_ptr<ChatEngine::Client> client) :
		m_client(std::move(client))
	{

	}

	std::unique_ptr<State> MainMenuState::onProcess()
	{
		return std::make_unique<ChatState>(std::move(m_client));
	}
}