#include "authentications/AuthResult.hpp"
#include <string>

namespace ChatEngine
{
	AuthResult::AuthResult(const bool isSuccessful, const std::string& message) :
		m_isSuccessful(isSuccessful),
		m_message(message)
	{

	}


	AuthResult::~AuthResult()
	{

	}

	const bool AuthResult::isSuccessful() const
	{
		return m_isSuccessful;
	}

	const std::string& AuthResult::getMessage() const
	{
		return m_message;
	}
}