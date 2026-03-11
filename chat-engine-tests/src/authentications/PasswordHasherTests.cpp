#include <gtest/gtest.h>
#include "authentications/PasswordHasher.hpp"
#include <string>

namespace ChatEngine::Tests
{
	TEST(PasswordHasherTests, hasPassword_ShouldReturnNonEmptyValue_WhenPassingInValidPassword)
	{
		ChatEngine::PasswordHasher sut;

		std::string result = sut.hashPassword("pass@word1");

		ASSERT_FALSE(result.empty());
	}

	TEST(PasswordHasherTests, verifyPassword_ShouldReturnTrue_WhenPassingValidValues)
	{
		std::string password = "pass@word1";
		ChatEngine::PasswordHasher sut;

		std::string hashedPassword = sut.hashPassword(password);
		bool result = sut.verifyPassword(password, hashedPassword);

		ASSERT_TRUE(result);
	}

	TEST(PasswordHasherTests, verifyPassword_ShouldReturnFalse_WhenPassingInvalidValues)
	{
		ChatEngine::PasswordHasher sut;

		std::string hashedPassword = sut.hashPassword("pass@word1");
		bool result = sut.verifyPassword("junk", hashedPassword);

		ASSERT_FALSE(result);
	}
}