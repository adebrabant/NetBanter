#include "networks/NetworkSystem.hpp"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#endif

#include <stdexcept>


namespace ChatEngine
{
    NetworkSystem::NetworkSystem()
    {
#ifdef _WIN32
        WSADATA data{};
        int result = WSAStartup(MAKEWORD(2, 2), &data);
        if (result != 0)
            throw std::runtime_error("WSAStartup failed");
#endif
    }

    NetworkSystem::~NetworkSystem()
    {
#ifdef _WIN32
        WSACleanup();
#endif
    }
}