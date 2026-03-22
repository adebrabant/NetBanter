#include <gtest/gtest.h>
#include "clients/Client.hpp"
#include "networks/TcpSocket.hpp"
#include <string>
#include <utility>

namespace ChatEngine::Tests
{
	TEST(ClientTests, getSocket_ShouldReturnSocket_WhenValidSocketIsGiven)
	{
		int expectedSocket = 1;
		TcpSocket tcpSocket(expectedSocket);
		Client sut(std::move(tcpSocket), "user-one");

		int result = sut.getSocket();

		EXPECT_EQ(result, expectedSocket);
	}

	TEST(ClientTests, getUsername_ShouldReturnUsername_WhenValidUsernameIsGiven)
	{
		std::string expectedUsername = "user-one";
		TcpSocket tcpSocket(1);
		Client sut(std::move(tcpSocket), expectedUsername);

		std::string result = sut.getUsername();

		EXPECT_EQ(result, expectedUsername);
	}
}