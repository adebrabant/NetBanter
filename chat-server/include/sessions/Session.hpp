#pragma once

#include "messages/Messenger.hpp"
#include "authentications/Authenticator.hpp"
#include "users/UserRepository.hpp"
#include "networks/TcpSocket.hpp"
#include "clients/ClientManager.hpp"
#include "clients/Client.hpp"
#include "fsms/SessionStateMachine.hpp"
#include <memory>

namespace ChatEngine
{
	class Command;
}

namespace ChatServer
{

	class Session
	{
	public:
		Session(
			ChatEngine::TcpSocket& tcpSocket,
			ChatEngine::Authenticator& authenticator,
			ChatEngine::ClientManager& clientManager,
			ChatEngine::UserRepository& userRepository
		);

		~Session() = default;
		void run();

	private:
		ChatEngine::Authenticator& m_authenticator;
		ChatEngine::ClientManager& m_clientManager;
		ChatEngine::UserRepository& m_userRepository;
		ChatEngine::Messenger m_messenger;
		ChatServer::SessionStateMachine m_stateMachine;
		std::unique_ptr<ChatEngine::Client> m_client;
	};
}