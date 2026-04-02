#pragma once

#include "fsms/SessionState.hpp"
#include "fsms/SessionStateMachine.hpp"
#include "clients/Client.hpp"
#include "authentications/Authenticator.hpp"
#include "users/UserRepository.hpp"
#include "clients/ClientManager.hpp"
#include <string>

namespace ChatEngine
{
	class Command;
}

namespace ChatServer
{
	class UnauthenticatedState : public SessionState
	{
	public:
		UnauthenticatedState(
			ChatServer::SessionStateMachine& stateMachine,
			ChatEngine::Client* client,
			ChatEngine::Authenticator& authenticator,
			ChatEngine::ClientManager& clientManager,
			ChatEngine::UserRepository& userRepository
		);
		void process() override;

	private:
		void applyResult(const ChatEngine::AuthResult& result, const std::string& message, const std::string& username);

	private:
		ChatServer::SessionStateMachine& m_stateMachine;
		ChatEngine::Client* m_client;
		ChatEngine::Authenticator& m_authenticator;
		ChatEngine::ClientManager& m_clientManager;
		ChatEngine::UserRepository& m_userRepository;
	};
}