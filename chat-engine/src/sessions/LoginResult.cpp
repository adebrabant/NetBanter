#include "sessions/LoginResult.hpp"
#include <string>

namespace ChatEngine
{
	LoginResult::LoginResult(const bool isSuccessful, const std::string& message) :
		m_isSuccessful(isSuccessful),
		m_message(message)
	{

	}


	LoginResult::~LoginResult()
	{

	}

	const bool LoginResult::isSuccessful() const
	{
		return m_isSuccessful;
	}

	const std::string& LoginResult::getMessage() const
	{
		return m_message;
	}
}