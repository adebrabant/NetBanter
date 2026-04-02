#pragma once

#include "networks/TcpSocket.hpp"
#include "networks/NetworkSystem.hpp"
#include "fsms/StateMachine.hpp"

namespace ChatClient
{
	class Application
	{
	public:
		Application();
		~Application() = default;
		int run();

	private:
		ChatEngine::NetworkSystem m_network;
		ChatEngine::TcpSocket m_tcpSocket;
		ChatClient::StateMachine m_stateMachine;
	};
}