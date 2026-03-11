#include <gtest/gtest.h>
#include "users/User.hpp"

#include <cstdint>
#include <string>

namespace ChatEngine::Tests
{
	TEST(UserTests, getId_ShouldReturn_GivenId)
	{
		uint32_t expectedId = 12345;
		ChatEngine::User user(
			expectedId, 
			std::string("testUser"), 
			std::string("pass")
		);

		uint32_t actualId = user.getId();

		EXPECT_EQ(expectedId, actualId);
	}

	TEST(UserTests, getUserName_ShouldReturn_GivenUserName)
	{
		uint32_t id = 1;
		std::string expectedUsername("testUser");
		ChatEngine::User user(
			id,
			expectedUsername,
			std::string("pass")
		);

		const std::string& actualUsername = user.getUsername();

		EXPECT_EQ(expectedUsername, actualUsername);
	}
}