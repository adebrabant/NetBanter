#pragma once

#include <cstdint>
#include <string>

namespace ChatEngine
{
	class User
	{
	public:
		User(uint32_t id, const std::string& userName, const std::string& passwordHash);
		~User() = default;
		uint32_t getId() const { return m_id; }
		const std::string& getUsername() const { return m_username; }
		const std::string& getPasswordHash() const { return m_passwordHash; }
		bool operator==(const User&) const = default;

	private:
		uint32_t m_id;
		std::string m_username;
		std::string m_passwordHash;
	};
}