#pragma once

#include "Client.hpp"
#include <unordered_map>
#include <string>
#include <vector>

namespace ChatEngine
{
	// ToDo: look into renaming this into ClientLookup
	class ClientManager
	{
	public:
		ClientManager();
		~ClientManager() = default;
		void add(Client* client);
		void remove(int socket);
		Client* findBySocket(int socket);
		Client* findByUsername(std::string username);
		std::vector<Client*> findAll();

	private:
		std::unordered_map<int, Client*> m_clientSockets;
		std::unordered_map<std::string, Client*> m_clientUsernames;
	};
}