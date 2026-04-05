#pragma once

#include "states/State.hpp"
#include "fsms/StateMachine.hpp"
#include "clients/Client.hpp"
#include "authentications/Authenticator.hpp"
#include "users/UserRepository.hpp"
#include "clients/ClientManager.hpp"
#include "authentications/AuthResult.hpp"
#include <string>

namespace ChatEngine
{
	class Command;
}

namespace ChatServer
{
	class UnauthenticatedState : public ChatEngine::State
	{
	public:
		UnauthenticatedState(
			ChatEngine::StateMachine& stateMachine,
			ChatEngine::Client* client,
			ChatEngine::Authenticator& authenticator,
			ChatEngine::ClientManager& clientManager,
			ChatEngine::UserRepository& userRepository
		);
		void handle() override;

	private:
		void applyResult(
			const ChatEngine::AuthResult& result, 
			const std::string& message, const std::string& username
		);

	private:
		ChatEngine::Client* m_client;
		ChatEngine::Authenticator& m_authenticator;
		ChatEngine::ClientManager& m_clientManager;
		ChatEngine::UserRepository& m_userRepository;
	};
}