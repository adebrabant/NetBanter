#include <gtest/gtest.h>
#include "authentications/AuthResult.hpp"
#include <string>

namespace ChatEngine::Tests
{
	TEST(AuthResultTests, isSuccessful_ShouldReturnTrue_WhenLoginIsSeccessful)
	{
		ChatEngine::AuthResult sut(true, "Login successful");

		EXPECT_TRUE(sut.isSuccessful());
	}

	TEST(AuthResultTests, isSuccessful_ShouldReturnFalse_WhenLoginIsUnsuccessful)
	{
		ChatEngine::AuthResult sut(false, "Login unsuccessful");

		EXPECT_FALSE(sut.isSuccessful());
	}

	TEST(AuthResultTests, getMessage_ShouldReturnValidMessage_WhenMessageIsSupplied)
	{
		std::string expectedMessage = "Login successful";
		ChatEngine::AuthResult sut(true, expectedMessage);

		EXPECT_EQ(sut.getMessage(), expectedMessage);
	}
}