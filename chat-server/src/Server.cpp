#include "Server.hpp"
#include "networks/TcpServer.hpp"
#include "sessions/Session.hpp"
#include "authentications/AuthResult.hpp"

#include <thread>
#include <iostream>
#include <utility>

namespace ChatServer
{
    Server::Server() :
        m_network(),
        m_clientManager(),
        m_messenger(),
        m_userRepository(),
        m_authenticator(m_userRepository)
    {

    }

    int Server::run()
    {
        ChatEngine::TcpServer server(12345);
        std::cout << "Server started on port 12345...\n";

        m_authenticator.registerUser("user1", "password");

        while (true)
        {
            auto socket = server.acceptClient();

            std::thread([socket = std::move(socket), this]() mutable {
                Session session(
                    socket,
                    m_authenticator,
                    m_clientManager,
                    m_userRepository
                );

                session.run();
                }).detach();
        }

        return 0;
    }
}