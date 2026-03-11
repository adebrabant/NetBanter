#include "authentications/Authenticator.hpp"
#include "sessions/LoginResult.hpp"
#include "users/UserRepository.hpp"
#include "users/User.hpp"

#include <string>

namespace ChatEngine
{
	Authenticator::Authenticator(UserRepository& userRepository) :
		m_userRepository(userRepository),
		m_passwordHasher()
	{

	}

	Authenticator::~Authenticator()
	{

	}

	LoginResult Authenticator::registerUser(const std::string& username, const std::string& password)
	{
		if (m_userRepository.hasUser(username))
			return LoginResult(false, "Username already exists did you mean to login?");

		std::string passwordHash = m_passwordHasher.hashPassword(password);
		User newUser{ 1, username, passwordHash };
		m_userRepository.add(newUser);

		return LoginResult(true, "Account successfully created!");
	}

	LoginResult Authenticator::loginUser(const std::string& username, const std::string& password) const
	{
		if (!m_userRepository.hasUser(username))
			return LoginResult(false, "Username doesn't exist did you mean to create an account?");

		if (!isValidCredentials(username, password))
			return LoginResult(false, "Username and password attempt failed!");

		return LoginResult(true, "Login successful");
	}

	bool Authenticator::isValidCredentials(const std::string& username, const std::string& password) const
	{
		User user = m_userRepository.getByUsername(username);

		return m_passwordHasher.verifyPassword(password, user.getPasswordHash());;
	}
}