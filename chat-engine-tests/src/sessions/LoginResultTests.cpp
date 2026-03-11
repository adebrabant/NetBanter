#include <gtest/gtest.h>
#include "sessions/LoginResult.hpp"
#include <string>

namespace ChatEngine::Tests
{
	TEST(LoginResultTests, isSuccessful_ShouldReturnTrue_WhenLoginIsSeccessful)
	{
		ChatEngine::LoginResult sut(true, "Login successful");

		EXPECT_TRUE(sut.isSuccessful());
	}

	TEST(LoginResultTests, isSuccessful_ShouldReturnFalse_WhenLoginIsUnsuccessful)
	{
		ChatEngine::LoginResult sut(false, "Login unsuccessful");

		EXPECT_FALSE(sut.isSuccessful());
	}

	TEST(LoginResultTests, getMessage_ShouldReturnValidMessage_WhenMessageIsSupplied)
	{
		std::string expectedMessage = "Login successful";
		ChatEngine::LoginResult sut(true, expectedMessage);

		EXPECT_EQ(sut.getMessage(), expectedMessage);
	}
}