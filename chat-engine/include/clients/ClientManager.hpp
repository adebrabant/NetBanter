#pragma once

#include "Client.hpp"
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>

namespace ChatEngine
{
	class ClientManager
	{
	public:
		ClientManager();
		~ClientManager() = default;
		void add(std::unique_ptr<Client> client);
		void remove(int socket);
		Client* findBySocket(int socket);
		Client* findByUsername(std::string username);
		std::vector<Client*> findAll();

	private:
		std::unordered_map<int, std::unique_ptr<Client>> m_clientSockets;
		std::unordered_map<std::string, Client*> m_clientUsernames;
	};
}