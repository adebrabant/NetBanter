#include "clients/ClientManager.hpp"
#include <clients/Client.hpp>
#include <string> 
#include <vector>
#include <utility>

namespace ChatEngine
{
	ClientManager::ClientManager() :
		m_clientSockets(),
		m_clientUsernames()
	{

	}

	void ClientManager::add(Client* client)
	{
		int socket = client->getSocket();
		std::string username = client->getUsername();

		m_clientSockets.emplace(socket, std::move(client));
		m_clientUsernames.emplace(username, m_clientSockets[socket]);
	}

	void ClientManager::remove(int socket)
	{
		auto it = m_clientSockets.find(socket);
		if (it != m_clientSockets.end())
		{
			m_clientUsernames.erase(it->second->getUsername());
			m_clientSockets.erase(it->first);
		}
	}

	Client* ClientManager::findBySocket(int socket)
	{
		auto it = m_clientSockets.find(socket);
		return (it != m_clientSockets.end()) ? it->second : nullptr;
	}

	Client* ClientManager::findByUsername(std::string username)
	{
		auto it = m_clientUsernames.find(username);
		return (it != m_clientUsernames.end()) ? it->second : nullptr;
	}

	std::vector<Client*> ClientManager::findAll()
	{
		std::vector<Client*> clients;
		clients.reserve(m_clientUsernames.size());
		for (auto& [username, client] : m_clientUsernames)
		{
			clients.emplace_back(client);
		}

		return clients;
	}
}