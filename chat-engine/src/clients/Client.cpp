#include "clients/Client.hpp"
#include <string>

namespace ChatEngine
{
	Client::Client(int socket, std::string username) :
		m_socket(socket),
		m_username(username)
	{

	}
}