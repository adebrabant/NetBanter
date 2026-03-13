#include <gtest/gtest.h>
#include "clients/Client.hpp"
#include "clients/ClientManager.hpp"
#include <string>
#include <memory>
#include <utility>

namespace ChatEngine::Tests
{
	TEST(ClientManagerTests, remove_ShouldRemoveClient_WhenValidSocketIsGiven)
	{
		ClientManager sut;
		int socket = 1;
		auto client = std::make_unique<Client>(socket, "user-one");

		sut.add(std::move(client));
		sut.remove(socket);
		auto result = sut.findBySocket(socket);

		EXPECT_EQ(result, nullptr);
	}

	TEST(ClientManagerTests, remove_ShouldNotRemoveClient_WhenInvalidSocketIsGiven)
	{
		ClientManager sut;
		int socket = 1;
		auto client = std::make_unique<Client>(socket, "user-one");

		sut.add(std::move(client));
		sut.remove(999);
		auto result = sut.findBySocket(socket);

		EXPECT_EQ(result->getSocket(), socket);
	}

	TEST(ClientManagerTests, findBySocket_ShouldReturnClient_WhenValidSocketIsGiven)
	{
		ClientManager sut;
		int socket = 1;
		std::string username = "user-one";
		auto client = std::make_unique<Client>(socket, username);

		sut.add(std::move(client));
		auto result = sut.findBySocket(socket);

		EXPECT_EQ(result->getSocket(), socket);
		EXPECT_EQ(result->getUsername(), username);
	}

	TEST(ClientManagerTests, findBySocket_ShouldReturnNullPtr_WhenInvalidSocketIsGiven)
	{
		ClientManager sut;
		auto client = std::make_unique<Client>(1, "user-one");

		sut.add(std::move(client));
		auto result = sut.findBySocket(2);

		EXPECT_EQ(result, nullptr);
	}

	TEST(ClientManagerTests, findByUsername_ShouldReturnClient_WhenValidUsernameIsGiven)
	{
		ClientManager sut;
		int socket = 1;
		std::string username = "user-one";
		auto client = std::make_unique<Client>(socket, username);

		sut.add(std::move(client));
		auto result = sut.findByUsername(username);

		EXPECT_EQ(result->getSocket(), socket);
		EXPECT_EQ(result->getUsername(), username);
	}

	TEST(ClientManagerTests, findByUsername_ShouldReturnNullPtr_WhenInvalidUsernameIsGiven)
	{
		ClientManager sut;
		auto client = std::make_unique<Client>(1, "user-one");

		sut.add(std::move(client));
		auto result = sut.findByUsername("user-three");

		EXPECT_EQ(result, nullptr);
	}

	TEST(ClientManagerTests, findAll_ShouldReturnClients_WhenCalled)
	{
		ClientManager sut;
		auto clientOne = std::make_unique<Client>(1, "user-one");
		auto clientTwo = std::make_unique<Client>(2, "user-two");

		sut.add(std::move(clientOne));
		sut.add(std::move(clientTwo));
		auto results = sut.findAll();

		EXPECT_EQ(results.size(), 2);
	}

	TEST(ClientManagerTests, findAll_ShouldReturnEmptyVector_WhenNoClientsExist)
	{
		ClientManager sut;

		auto results = sut.findAll();

		EXPECT_TRUE(results.empty());
	}
}