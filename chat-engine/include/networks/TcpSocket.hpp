#pragma once

#include <string>
#include <cstdint>

namespace ChatEngine
{
    class TcpSocket
    {
    public:
        TcpSocket();
        explicit TcpSocket(int socket);
        ~TcpSocket();

        TcpSocket(const TcpSocket&) = delete;
        TcpSocket& operator=(const TcpSocket&) = delete;

        TcpSocket(TcpSocket&& other) noexcept;
        TcpSocket& operator=(TcpSocket&& other) noexcept;

        size_t send(const std::string& data) const;
        int receive(char* buffer, size_t bufferSize) const;
        void connectTo(const std::string& host, uint16_t port);
        int getRawSocket() const { return m_socket; };

    private:
        int m_socket{ -1 };
    };
}