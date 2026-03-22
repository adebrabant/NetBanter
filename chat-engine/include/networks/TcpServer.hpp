#pragma once

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

namespace ChatEngine
{
	class TcpSocket;

	class TcpServer
	{
	public:
		TcpServer(int port);
		~TcpServer();

		TcpServer(const TcpServer&) = delete;
		TcpServer& operator=(const TcpServer&) = delete;

		TcpSocket acceptClient();

	private:
		void createSocket();
		void setReuseAddress();
		void bindSocket();
		void startListener();

	private:
		int m_port;
#ifdef _WIN32
		SOCKET m_serverSocket{ INVALID_SOCKET };
#else
		int m_serverSocket{ -1 };
#endif
	};
}