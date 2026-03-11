#include <gtest/gtest.h>
#include "users/User.hpp"
#include "users/UserRepository.hpp"
#include <stdexcept>

namespace ChatEngine::Tests
{
	TEST(UserRepositoryTests, add_ShouldCreateNewUser_WhenCalled)
	{
		ChatEngine::User user(1, "user", "pass");
		ChatEngine::UserRepository sut;

		sut.add(user);
		const ChatEngine::User& expectedUser = sut.getById(user.getId());

		EXPECT_EQ(user, expectedUser);
	}

	TEST(UserRepositoryTests, getById_ShouldReturnExistingUser_WhenPassingInExistingUserId)
	{
		ChatEngine::User userOne(1, "user", "pass");
		ChatEngine::User userTwo(2, "userTwo", "pass");
		ChatEngine::UserRepository sut;

		sut.add(userOne);
		sut.add(userTwo);
		const ChatEngine::User& expectedUser = sut.getById(userOne.getId());

		EXPECT_EQ(userOne, expectedUser);
		EXPECT_NE(userTwo, expectedUser);
	}

	TEST(UserRepositoryTests, removeById_ShouldRemoveExistingUser_WhenPassingInExistingUserId)
	{
		ChatEngine::User userOne(1, "user", "pass");
		ChatEngine::UserRepository sut;

		sut.add(userOne);
		sut.removeById(userOne.getId());

		EXPECT_THROW(sut.getById(userOne.getId()), std::runtime_error);
	}

	TEST(UserRepositoryTests, removeByUsername_ShouldRemoveExistingUser_WhenPassingInExistingUsername)
	{
		ChatEngine::User userOne(1, "user", "pass");
		ChatEngine::UserRepository sut;

		sut.add(userOne);
		sut.removeByUsername(userOne.getUsername());

		EXPECT_THROW(sut.getById(userOne.getId()), std::runtime_error);
	}

	TEST(UserRepositoryTests, hasUser_ShouldReturnTrue_WhenUserDoesExist)
	{
		ChatEngine::User userOne(1, "user", "pass");
		ChatEngine::UserRepository sut;

		sut.add(userOne);

		EXPECT_TRUE(sut.hasUser(userOne.getUsername()));
	}

	TEST(UserRepositoryTests, hasUser_ShouldReturnFalse_WhenUserDoesNotExist)
	{
		ChatEngine::User userOne(1, "user", "pass");
		ChatEngine::UserRepository sut;

		EXPECT_FALSE(sut.hasUser(userOne.getUsername()));
	}
}