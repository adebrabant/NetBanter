#include "fsms/ChatState.hpp"
#include "clients/Client.hpp"
#include "fsms/State.hpp"

#include <utility>
#include <memory>
#include <iostream>
#include <string>
#include <thread>
#include <stdexcept>

namespace ChatClient
{
	ChatState::ChatState(std::unique_ptr<ChatEngine::Client> client) :
		m_client(std::move(client))
	{

	}

	std::unique_ptr<State> ChatState::onProcess()
	{
        std::thread receiveThread([this]() {
            while (true) {
                try {
                    std::string message = m_client->receiveMessage();
                    if (!message.empty())
                        std::cout << message << std::endl;
                }
                catch (const std::runtime_error&) {
                    std::cout << "Disconnected from server" << std::endl;
                    break;
                }
            }
            });

        std::cout << "Connected! Type messages and press Enter:" << std::endl;

        std::string input;
        do 
        {
            std::getline(std::cin, input);
            if (input.empty())
                continue;

            if (!m_client->sendMessage(input))
                std::cout << "Failed to send message!" << std::endl;
        } while (input != "quit");

        receiveThread.join(); 

		return std::unique_ptr<State>();
	}
}