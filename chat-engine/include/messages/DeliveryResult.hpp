#pragma once

#include <string>

namespace ChatEngine
{
	class DeliveryResult
	{
	public:
		DeliveryResult(bool success, std::string message);
		bool isSuccess() const { return m_success; }
		const std::string& getMessage() const { return m_message; }

	private:
		const bool m_success;
		const std::string m_message;
	};
}