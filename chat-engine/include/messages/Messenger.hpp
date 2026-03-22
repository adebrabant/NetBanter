#pragma once
#include <string>

namespace ChatEngine
{
	class Client;
	class Message;
	class DeliveryResult;

	class Messenger
	{
	public:
		Messenger() = default;
		~Messenger() = default;
		DeliveryResult deliver(const Message& message, Client* recipient);
		
	private:
		std::string formatMessage(const Message& message);
	};
}