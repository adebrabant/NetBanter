#include "users/User.hpp"
#include <cstdint>
#include <string>

namespace ChatEngine
{
	User::User(uint32_t id, const std::string& userName, const std::string& passwordHash) : 
		m_id(id), m_username(userName), 
		m_passwordHash(passwordHash)
	{

	}
}