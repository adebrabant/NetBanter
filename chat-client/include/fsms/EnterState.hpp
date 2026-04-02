#pragma once
#include "fsms/State.hpp"
#include "networks/TcpSocket.hpp"
#include <memory>

namespace ChatClient
{
	class EnterState : public State
	{
	public:
		EnterState(ChatEngine::TcpSocket& tcpSocket);
		std::unique_ptr<State> onProcess() override;

	private:
		ChatEngine::TcpSocket& m_tcpSocket;
	};
}