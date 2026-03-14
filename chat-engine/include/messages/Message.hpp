#pragma once

#include <string>
#include <corecrt.h>

namespace ChatEngine
{
	class Message
	{
	public:
		Message(const std::string& sender, const std::string& recipient, const std::string& content, time_t& timestamp);
		~Message() = default;
		const std::string getSender() const { return m_sender; }
		const std::string getRecipient() const { return m_recipient; }
		const std::string getContent() const { return m_content; }
		const time_t getTimestamp() const { return m_timestamp; }

	private:
		const std::string m_sender;
		const std::string m_recipient;
		const std::string m_content;
		time_t m_timestamp;
	};
}