#include "sessions/Session.hpp"
#include "authentications/Authenticator.hpp"
#include "clients/ClientManager.hpp"
#include "networks/TcpSocket.hpp"
#include "users/UserRepository.hpp"
#include "clients/Client.hpp"
#include "states/AuthenticatedState.hpp"
#include "states/UnauthenticatedState.hpp"

#include <utility>
#include <memory>

namespace ChatServer
{
	Session::Session(
        ChatEngine::TcpSocket& tcpSocket,
		ChatEngine::Authenticator& authenticator, 
		ChatEngine::ClientManager& clientManager, 
		ChatEngine::UserRepository& userRepository
	) :
		m_authenticator(authenticator),
		m_clientManager(clientManager),
		m_userRepository(userRepository),
		m_messenger(),
        m_stateMachine(),
        m_client(std::make_unique<ChatEngine::Client>(std::move(tcpSocket)))
	{
        m_stateMachine.addState<UnauthenticatedState>(
            m_stateMachine,
            m_client.get(),
            authenticator,
            clientManager,
            userRepository
         );

        m_stateMachine.addState<AuthenticatedState>(
            m_stateMachine,
            m_client.get()
        );
	}

	void Session::run()
	{
        m_stateMachine.moveToState<UnauthenticatedState>();
        m_stateMachine.run();
	}
}