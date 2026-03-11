#pragma once

#include "users/UserRepository.hpp"
#include "authentications/PasswordHasher.hpp"
#include <string>

namespace ChatEngine
{
	class LoginResult;

	class Authenticator
	{
	public:
		Authenticator(UserRepository& userRepository);
		~Authenticator();
		LoginResult registerUser(const std::string& username, const std::string& password);
		LoginResult loginUser(const std::string& username, const std::string& password) const;

	private:
		bool isValidCredentials(const std::string& username, const std::string& password) const;

	private:
		UserRepository& m_userRepository;
		PasswordHasher m_passwordHasher;
	};
}