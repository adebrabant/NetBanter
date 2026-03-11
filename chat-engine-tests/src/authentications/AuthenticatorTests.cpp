#include <gtest/gtest.h>
#include "authentications/Authenticator.hpp"
#include "authentications/AuthResult.hpp"
#include "users/UserRepository.hpp"
#include <string>

namespace ChatEngine::Tests
{
	TEST(AuthenticatorTests, registerUser_ShouldReturnSuccessfulAuthResult_WhenCreatingUniqueAccount)
	{
		std::string username = "test-user";
		std::string password = "pass@word1";
		ChatEngine::UserRepository userRepo;
		ChatEngine::Authenticator sut(userRepo);

		const ChatEngine::AuthResult result = sut.registerUser(username, password);

		EXPECT_TRUE(result.isSuccessful());
	}

	TEST(AuthenticatorTests, registerUser_ShouldReturnFailedAuthResult_WhenCreatingNonUniqueAccount)
	{
		std::string username = "test-user";
		std::string password = "pass@word1";
		ChatEngine::UserRepository userRepo;
		ChatEngine::Authenticator sut(userRepo);

		sut.registerUser(username, password);
		const ChatEngine::AuthResult result = sut.registerUser(username, password);

		EXPECT_FALSE(result.isSuccessful());
	}

	TEST(AuthenticatorTests, loginUser_ShouldReturnSuccessfulAuthResult_WhenLoginIsSuccessful)
	{
		std::string username = "test-user";
		std::string password = "pass@word1";
		ChatEngine::UserRepository userRepo;
		ChatEngine::Authenticator sut(userRepo);

		sut.registerUser(username, password);
		const ChatEngine::AuthResult result = sut.loginUser(username, password);

		EXPECT_TRUE(result.isSuccessful());
	}

	TEST(AuthenticatorTests, loginUser_ShouldReturnFailedAuthResult_WhenLoginIsUnsuccessful)
	{
		std::string username = "test-user";
		ChatEngine::UserRepository userRepo;
		ChatEngine::Authenticator sut(userRepo);

		const ChatEngine::AuthResult result = sut.loginUser(username, "no-good");

		EXPECT_FALSE(result.isSuccessful());
	}
}