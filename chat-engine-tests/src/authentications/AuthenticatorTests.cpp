#include <gtest/gtest.h>
#include "authentications/Authenticator.hpp"
#include "users/UserRepository.hpp"
#include "sessions/LoginResult.hpp"
#include <string>

namespace ChatEngine::Tests
{
	TEST(AuthenticatorTests, registerUser_ShouldReturnSuccessfulLoginResult_WhenCreatingUniqueAccount)
	{
		std::string username = "test-user";
		std::string password = "pass@word1";
		ChatEngine::UserRepository userRepo;
		ChatEngine::Authenticator sut(userRepo);

		const ChatEngine::LoginResult result = sut.registerUser(username, password);

		EXPECT_TRUE(result.isSuccessful());
	}

	TEST(AuthenticatorTests, registerUser_ShouldReturnFailedLoginResult_WhenCreatingNonUniqueAccount)
	{
		std::string username = "test-user";
		std::string password = "pass@word1";
		ChatEngine::UserRepository userRepo;
		ChatEngine::Authenticator sut(userRepo);

		sut.registerUser(username, password);
		const ChatEngine::LoginResult result = sut.registerUser(username, password);

		EXPECT_FALSE(result.isSuccessful());
	}

	TEST(AuthenticatorTests, loginUser_ShouldReturnSuccessfulLoginResult_WhenLoginIsSuccessful)
	{
		std::string username = "test-user";
		std::string password = "pass@word1";
		ChatEngine::UserRepository userRepo;
		ChatEngine::Authenticator sut(userRepo);

		sut.registerUser(username, password);
		const ChatEngine::LoginResult result = sut.loginUser(username, password);

		EXPECT_TRUE(result.isSuccessful());
	}

	TEST(AuthenticatorTests, loginUser_ShouldReturnFailedLoginResult_WhenLoginIsUnsuccessful)
	{
		std::string username = "test-user";
		ChatEngine::UserRepository userRepo;
		ChatEngine::Authenticator sut(userRepo);

		const ChatEngine::LoginResult result = sut.loginUser(username, "no-good");

		EXPECT_FALSE(result.isSuccessful());
	}
}