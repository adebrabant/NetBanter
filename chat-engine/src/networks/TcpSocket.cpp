#include "networks/TcpSocket.hpp"

#ifdef _WIN32
#include <winsock2.h>
#include <Ws2tcpip.h> 
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <unistd.h>
#endif

#include <stdexcept>
#include <string>
#include <ws2def.h>
#include <cstdint>

namespace ChatEngine
{
	TcpSocket::TcpSocket() :
		m_socket(-1)
	{

	}

	TcpSocket::TcpSocket(int socket) :
		m_socket(socket)
	{

	}

	TcpSocket::~TcpSocket()
	{
		if (m_socket == -1)
			return;

#ifdef _WIN32
		::closesocket(m_socket);
#else
		::close(m_socket);
#endif
	}

	TcpSocket::TcpSocket(TcpSocket&& other) noexcept :
		m_socket(other.m_socket)
	{
		other.m_socket = -1;
	}

	TcpSocket& TcpSocket::operator=(TcpSocket&& other) noexcept
	{
		if (this != &other)
		{
#ifdef _WIN32
			if (m_socket != -1)
				::closesocket(m_socket);
#else
			if (m_socket != -1)
				::close(m_socket);
#endif

			m_socket = other.m_socket;
			other.m_socket = -1;
		}

		return *this;
	}

	size_t TcpSocket::send(const std::string& data) const
	{
		return ::send(m_socket, data.c_str(), data.size(), 0);
	}

	int TcpSocket::receive(char* buffer, size_t bufferSize) const
	{
		if (m_socket == -1)
			throw std::runtime_error("Socket not connected");

#ifdef _WIN32
		int received = recv(m_socket, buffer, static_cast<int>(bufferSize), 0);
#else
		int received = ::recv(m_socket, buffer, bufferSize, 0);
#endif

		if (received < 0)
			throw std::runtime_error("Receive failed");

		return received;
	}

	void TcpSocket::connectTo(const std::string& host, uint16_t port)
	{
		m_socket = ::socket(AF_INET, SOCK_STREAM, 0);
#ifdef _WIN32
		if (m_socket == INVALID_SOCKET)
			throw std::runtime_error("Failed to create socket");
#else
		if (m_socket < 0)
			throw std::runtime_error("Failed to create socket");
#endif

		sockaddr_in socketAddress{};
		socketAddress.sin_family = AF_INET;
		socketAddress.sin_port = htons(port);

#ifdef _WIN32

		if (InetPtonA(AF_INET, host.c_str(), &socketAddress.sin_addr) != 1)
			throw std::runtime_error("Invalid IP address");

		if (::connect(m_socket, reinterpret_cast<sockaddr*>(&socketAddress), sizeof(socketAddress)) < 0)
		{
			int error = WSAGetLastError();
			throw std::runtime_error("Connection failed, WSA error: " + std::to_string(error));
		}
#else
		if (inet_pton(AF_INET, host.c_str(), &socketAddress.sin_addr) <= 0)
			throw std::runtime_error("Invalid IP address");

		if (::connect(m_socket, reinterpret_cast<sockaddr*>(&socketAddress), sizeof(socketAddress)) < 0)
			throw std::runtime_error("Connection failed");
#endif
	}
}