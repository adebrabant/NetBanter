#pragma once

#include <string>

namespace ChatEngine 
{
	class LoginResult
	{
	public:
		LoginResult(const bool isSuccessful, const std::string& message);
		~LoginResult();
		const bool isSuccessful() const;
		const std::string& getMessage() const;

	private:
		const bool m_isSuccessful;
		const std::string& m_message;
	};
}