#include <gtest/gtest.h>
#include "messages/Message.hpp"
#include <string>
#include <corecrt.h>

namespace ChatEngine::Tests
{
	TEST(MessageTests, getSender_ShouldReturnSender_WhenGivenValidSender)
	{
		time_t timestamp{ 0 };
		const std::string sender{ "user-one" };
		const std::string recipient{ "user-two" };
		Message sut(sender, recipient, "hello", timestamp);

		const std::string result = sut.getSender();

		EXPECT_EQ(result, sender);
	}

	TEST(MessageTests, getRecipient_ShouldReturnRecipient_WhenGivenValidRecipient)
	{
		time_t timestamp{ 0 };
		const std::string sender{ "user-one" };
		const std::string recipient{ "user-two" };
		Message sut(sender, recipient, "hello", timestamp);

		const std::string result = sut.getRecipient();

		EXPECT_EQ(result, recipient);
	}

	TEST(MessageTests, getContent_ShouldReturnContent_WhenGivenValidContent)
	{
		time_t timestamp{ 0 };
		const std::string sender{ "user-one" };
		const std::string recipient{ "user-two" };
		const std::string content{ "Hello! How are you today!" };
		Message sut(sender, recipient, content, timestamp);

		const std::string result = sut.getContent();

		EXPECT_EQ(result, content);
	}

	TEST(MessageTests, getTimestamp_ShouldReturnTimestamp_WhenGivenValidTimestamp)
	{
		time_t timestamp{ 10 };
		const std::string sender{ "user-one" };
		const std::string recipient{ "user-two" };
		const std::string content{ "Hello! How are you today!" };
		Message sut(sender, recipient, content, timestamp);

		time_t result = sut.getTimestamp();

		EXPECT_EQ(result, timestamp);
	}
}