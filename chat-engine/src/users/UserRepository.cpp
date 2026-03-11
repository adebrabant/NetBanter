#include "users/UserRepository.hpp"
#include <users/User.hpp>
#include <string>
#include <cstdint>
#include <stdexcept>   

namespace ChatEngine
{
	UserRepository::UserRepository()
		: m_users()
	{

	}

	UserRepository::~UserRepository()
	{

	}

	void UserRepository::add(const User& user)
	{
		m_users.emplace(user.getUsername(), user);
	}

	const User& UserRepository::getById(uint32_t id) const
	{
		for (const auto& [username, user] : m_users)
		{
			if (user.getId() == id)
				return user;
		}

		throw std::runtime_error("User not found with id: " + std::to_string(id));

	}

	const User& UserRepository::getByUsername(const std::string& username) const
	{
		try
		{
			return m_users.at(username);
		}
		catch (const std::out_of_range&)
		{
			throw std::runtime_error("User not found: " + username);
		}
	}

	void UserRepository::removeById(uint32_t id)
	{
		const User& user = getById(id);
		removeByUsername(user.getUsername());
	}

	void UserRepository::removeByUsername(const std::string& username)
	{
		if (m_users.erase(username) == 0)
			throw std::runtime_error("User not found: " + username);
	}

	bool UserRepository::hasUser(const std::string& username) const
	{
		return m_users.contains(username);
	}
}