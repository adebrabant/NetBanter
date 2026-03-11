#include "authentications/PasswordHasher.hpp"
#include <string>
#include <sodium/core.h>
#include <stdexcept>  
#include <sodium/crypto_pwhash.h>

namespace ChatEngine
{
	std::string PasswordHasher::hashPassword(const std::string& password)
	{
		if (sodium_init() < 0)
			throw std::runtime_error("Failed to initialize lib-sodium");

		char hashed[crypto_pwhash_STRBYTES];

		if (crypto_pwhash_str(
			hashed,
			password.c_str(),
			password.size(),
			crypto_pwhash_OPSLIMIT_INTERACTIVE,
			crypto_pwhash_MEMLIMIT_INTERACTIVE) != 0)
		{
			throw std::runtime_error("Password hashing failed!");
		}

		return std::string(hashed);
	}

	bool PasswordHasher::verifyPassword(const std::string& password, const std::string& storedHash)
	{
		return crypto_pwhash_str_verify(
			storedHash.c_str(),
			password.c_str(),
			password.size()) == 0;
	}
}