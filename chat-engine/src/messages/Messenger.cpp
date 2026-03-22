#include "messages/Messenger.hpp"
#include "messages/DeliveryResult.hpp"
#include "messages/Message.hpp"
#include "clients/client.hpp"

#include <string>
#include <chrono>
#include <format>

namespace ChatEngine
{
    DeliveryResult Messenger::deliver(const Message& message, Client* recipient)
    {
        if (!recipient)
            return DeliveryResult(false, "Recipient client is null!");

        std::string formattedMessage = formatMessage(message);
        auto sentBytes = recipient->sendMessage(formattedMessage);

        if (!recipient->sendMessage(formattedMessage))
            return DeliveryResult(false, "Failed to send");

        return DeliveryResult(true, "Successfully sent message to socket");
    }

    std::string Messenger::formatMessage(const Message& message)
    {
        auto timestamp = std::chrono::system_clock::from_time_t(message.getTimestamp());

        std::string timeFormatted = std::format("{:%H:%M:%S}", timestamp);

        return std::format("{}: {} ({})", message.getSender(), message.getContent(), timeFormatted);
    }
}