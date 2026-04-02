#pragma once

#include "fsms/State.hpp"
#include "networks/TcpSocket.hpp"
#include <memory>

namespace ChatClient
{
	class RegistrationState : public State
	{
	public:
		RegistrationState(ChatEngine::TcpSocket& tcpSocket);
		std::unique_ptr<State> onProcess() override;

	private:
		ChatEngine::TcpSocket& m_tcpSocket;
	};
}