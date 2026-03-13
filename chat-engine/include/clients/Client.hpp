#pragma once

#include <string>

namespace ChatEngine
{
	class Client
	{
	public:
		Client(int socket, std::string username);
		int getSocket() const { return m_socket; }
		std::string getUsername() const { return m_username; }

	private:
		int m_socket;
		std::string m_username;
	};
}