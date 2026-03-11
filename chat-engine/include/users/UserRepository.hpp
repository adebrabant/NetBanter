#pragma once
#include "users/User.hpp"
#include <string>
#include <unordered_map>   
#include <cstdint>

namespace ChatEngine
{
	class UserRepository
	{
	public:
		UserRepository();
		~UserRepository();
		void add(const User& user);
		const User& getById(uint32_t id) const;
		const User& getByUsername(const std::string& username) const;
		void removeById(uint32_t id);
		void removeByUsername(const std::string& username);
		bool hasUser(const std::string& username) const;

	private:
		std::unordered_map<std::string, User> m_users;
	};
}