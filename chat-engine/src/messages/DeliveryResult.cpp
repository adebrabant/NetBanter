#include "messages/DeliveryResult.hpp"
#include <string>
#include <utility>

namespace ChatEngine
{
	DeliveryResult::DeliveryResult(bool success, std::string message) :
		m_success(success),
		m_message(std::move(message))
	{

	}
}