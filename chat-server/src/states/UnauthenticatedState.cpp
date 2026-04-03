#include "states/UnauthenticatedState.hpp"
#include "authentications/Authenticator.hpp"
#include "clients/Client.hpp"
#include "clients/ClientManager.hpp"
#include "users/UserRepository.hpp"
#include "parsers/CommandParser.hpp"
#include "authentications/AuthResult.hpp"
#include "states/AuthenticatedState.hpp"
#include "states/State.hpp"
#include "fsms/StateMachine.hpp"
#include <string>

namespace ChatServer
{
	UnauthenticatedState::UnauthenticatedState(
		ChatEngine::StateMachine& stateMachine,
		ChatEngine::Client* client, 
		ChatEngine::Authenticator& authenticator, 
		ChatEngine::ClientManager& clientManager, 
		ChatEngine::UserRepository& userRepository
	) :
		State(stateMachine),
		m_client(client),
		m_authenticator(authenticator),
		m_clientManager(clientManager),
		m_userRepository(userRepository)
	{

	}

	void UnauthenticatedState::handle()
	{
		while (m_client->getUsername().empty())
		{
			auto raw = m_client->receiveMessage();
			if (raw.empty())
				continue;

			const auto command = ChatEngine::CommandParser::parse(raw);

			if ((command.name != "LOGIN" && command.name != "REGISTER") || command.args.size() != 2)
				return;

			ChatEngine::AuthResult result =
				(command.name == "LOGIN")
				? m_authenticator.loginUser(command.args[0], command.args[1])
				: m_authenticator.registerUser(command.args[0], command.args[1]);

			applyResult(result, command.name, command.args[0]);
		}

		m_stateMachine.moveToState<AuthenticatedState>();
	}

	void UnauthenticatedState::applyResult(
		const ChatEngine::AuthResult& result, 
		const std::string& message, 
		const std::string& username)
	{
		if (!result.isSuccessful())
		{
			m_client->sendMessage(message + "_FAILED: " + result.getMessage());
			return;
		}

		m_client->sendMessage(message + "_SUCCESS");
		m_client->setUsername(username);
	}
}