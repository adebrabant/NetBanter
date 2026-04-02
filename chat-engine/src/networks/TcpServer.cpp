#include "networks/TcpServer.hpp"
#include "networks/TcpSocket.hpp"

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <ws2def.h>
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#include <stdexcept>

namespace ChatEngine
{
	TcpServer::TcpServer(int port) :
		m_port(port)
	{
		createSocket();
		setReuseAddress();
		bindSocket();
		startListener();
	}

	TcpServer::~TcpServer()
	{
#ifdef _WIN32
		if (m_serverSocket != INVALID_SOCKET)
			closesocket(m_serverSocket);
#else
		if (m_serverSocket >= 0)
			close(m_serverSocket);
#endif
	}

	TcpSocket TcpServer::acceptClient()
	{
		sockaddr_in clientAddress{};
#ifdef _WIN32
		int addressSize = sizeof(clientAddress);
		SOCKET clientSocket = ::accept(m_serverSocket, (sockaddr*)&clientAddress, &addressSize);
		if (clientSocket == INVALID_SOCKET)
			throw std::runtime_error("Client Accept failed!");
#else
		socklen_t addressSize = sizeof(clientAddress);
		int clientSocket = ::accept(m_serverSocket, (sockaddr*)&clientAddress, &addressSize);
		if (clientSocket < 0)
			throw std::runtime_error("Client Accept failed!");
#endif
		return TcpSocket(static_cast<int>(clientSocket));
	}

	void TcpServer::createSocket()
	{
#ifdef _WIN32
		m_serverSocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (m_serverSocket == INVALID_SOCKET)
			throw std::runtime_error("Failed to create server socket");
#else
		m_serverSocket = ::socket(AF_INET, SOCK_STREAM, 0);
		if (m_serverSocket < 0)
			throw std::runtime_error("Failed to create server socket");
#endif
	}

	void TcpServer::setReuseAddress()
	{
		int opt = 1;
#ifdef _WIN32
		::setsockopt(m_serverSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt));
#else
		::setsockopt(m_serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
#endif
	}

	void TcpServer::bindSocket()
	{
		sockaddr_in socketAddress{};
		socketAddress.sin_family = AF_INET;
		socketAddress.sin_port = htons(m_port);
		socketAddress.sin_addr.s_addr = INADDR_ANY;

#ifdef _WIN32
		if (::bind(m_serverSocket, (sockaddr*)&socketAddress, sizeof(socketAddress)) < 0)
			throw std::runtime_error("Bind failed");
#else
		if (::bind(m_serverSocket, (sockaddr*)&socketAddress, sizeof(socketAddress)) < 0) 
			throw std::runtime_error("Bind failed");
#endif
	}

	void TcpServer::startListener()
	{
#ifdef _WIN32
		if (::listen(m_serverSocket, SOMAXCONN) == SOCKET_ERROR)
			throw std::runtime_error("Listen failed");
#else
		if (::listen(m_serverSocket, SOMAXCONN) < 0)
			throw std::runtime_error("Listen failed");
#endif
	}
}