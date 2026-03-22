#pragma once

#include "networks/TcpSocket.hpp"
#include <string>

namespace ChatEngine
{
	class Client
	{
	public:
		Client(TcpSocket socket, std::string username);
		std::string getUsername() const { return m_username; }
		int getSocket() const { return m_socket.getRawSocket(); }
		bool sendMessage(const std::string& message);
		std::string receiveMessage();

	private:
		TcpSocket m_socket;
		std::string m_username;
	};
}