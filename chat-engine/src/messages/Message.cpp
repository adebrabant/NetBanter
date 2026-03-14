#include "messages/Message.hpp"
#include <corecrt.h>
#include <string>

namespace ChatEngine
{
	Message::Message(const std::string& sender, const std::string& recipient, const std::string& content, time_t& timestamp) :
		m_sender(sender),
		m_recipient(recipient),
		m_content(content),
		m_timestamp(timestamp)
	{

	}
}