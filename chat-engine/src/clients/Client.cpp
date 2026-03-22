#include "clients/Client.hpp"
#include <networks/TcpSocket.hpp>
#include <string>
#include <utility>

namespace ChatEngine
{
	Client::Client(TcpSocket socket, std::string username) :
		m_socket(std::move(socket)),
		m_username(username)
	{

	}

	bool Client::sendMessage(const std::string& message)
	{
		size_t sentBytes = m_socket.send(message);
		return sentBytes == message.size();
	}

	std::string Client::receiveMessage()
	{
		char buffer[1024];
		int bytesReceived = m_socket.receive(buffer, sizeof(buffer));
		return std::string(buffer, bytesReceived);
	}
}