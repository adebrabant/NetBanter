#pragma once

#include "networks/NetworkSystem.hpp"
#include "clients/ClientManager.hpp"
#include "messages/Messenger.hpp"
#include "authentications/Authenticator.hpp"
#include "users/UserRepository.hpp"

namespace ChatServer
{
	class Server
	{
	public:
		Server();
		~Server() = default;
		int run();

	private:
		ChatEngine::NetworkSystem m_network;
		ChatEngine::ClientManager m_clientManager;
		ChatEngine::Messenger m_messenger;
		ChatEngine::UserRepository m_userRepository;
		ChatEngine::Authenticator m_authenticator;
	};
}