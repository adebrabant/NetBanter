#pragma once

#include <string>

namespace ChatEngine 
{
	class AuthResult
	{
	public:
		AuthResult(const bool isSuccessful, const std::string& message);
		~AuthResult();
		const bool isSuccessful() const;
		const std::string& getMessage() const;

	private:
		const bool m_isSuccessful;
		const std::string& m_message;
	};
}