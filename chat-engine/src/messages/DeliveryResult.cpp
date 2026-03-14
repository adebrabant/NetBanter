#include "messages/DeliveryResult.hpp"
#include <string>

namespace ChatEngine
{
	DeliveryResult::DeliveryResult(bool success, const std::string& message) :
		m_success(success),
		m_message(message)
	{

	}
}