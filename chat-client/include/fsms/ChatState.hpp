#pragma once
#include "fsms/State.hpp"
#include "clients/Client.hpp"
#include <memory>

namespace ChatClient
{
	class ChatState : public State
	{
	public:
		ChatState(std::unique_ptr<ChatEngine::Client> client);
		std::unique_ptr<State> onProcess() override;

	private:
		std::unique_ptr<ChatEngine::Client> m_client;
	};
}