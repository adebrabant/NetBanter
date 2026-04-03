#pragma once

#include "networks/NetworkSystem.hpp"
#include "fsms/StateMachine.hpp"
#include "clients/Client.hpp"
#include <memory>

namespace ChatClient
{
	class Application
	{
	public:
		Application();
		~Application() = default;
		int run();

	private:
		void setup();

	private:
		ChatEngine::NetworkSystem m_network;
		ChatEngine::StateMachine m_stateMachine;
		std::unique_ptr<ChatEngine::Client> m_client;
	};
}