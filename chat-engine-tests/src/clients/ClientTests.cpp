#include <gtest/gtest.h>
#include "clients/Client.hpp"
#include <string>

namespace ChatEngine::Tests
{
	TEST(ClientTests, getSocket_ShouldReturnSocket_WhenValidSocketIsGiven)
	{
		int expectedSocket = 1;
		Client sut(1, "user-one");

		int result = sut.getSocket();

		EXPECT_EQ(result, expectedSocket);
	}

	TEST(ClientTests, getUsername_ShouldReturnUsername_WhenValidUsernameIsGiven)
	{
		std::string expectedUsername = "user-one";
		Client sut(1, expectedUsername);

		std::string result = sut.getUsername();

		EXPECT_EQ(result, expectedUsername);
	}
}