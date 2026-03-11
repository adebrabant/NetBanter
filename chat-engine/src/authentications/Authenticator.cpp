#include "authentications/Authenticator.hpp"
#include "authentications/AuthResult.hpp"
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

	AuthResult Authenticator::registerUser(const std::string& username, const std::string& password)
	{
		if (m_userRepository.hasUser(username))
			return AuthResult(false, "Username already exists did you mean to login?");

		std::string passwordHash = m_passwordHasher.hashPassword(password);
		User newUser{ 1, username, passwordHash }; // ToDo: need to handle the id creation
		m_userRepository.add(newUser);

		return AuthResult(true, "Account successfully created!");
	}

	AuthResult Authenticator::loginUser(const std::string& username, const std::string& password) const
	{
		if (!m_userRepository.hasUser(username))
			return AuthResult(false, "Username doesn't exist did you mean to create an account?");

		if (!isValidCredentials(username, password))
			return AuthResult(false, "Username and password attempt failed!");

		return AuthResult(true, "Login successful");
	}

	bool Authenticator::isValidCredentials(const std::string& username, const std::string& password) const
	{
		User user = m_userRepository.getByUsername(username);

		return m_passwordHasher.verifyPassword(password, user.getPasswordHash());;
	}
}