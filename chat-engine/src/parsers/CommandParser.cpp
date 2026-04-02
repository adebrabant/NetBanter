#include "parsers/CommandParser.hpp"
#include <sstream>

namespace ChatEngine 
{
	Command CommandParser::parse(const std::string& raw)
	{
		Command command;
		std::istringstream stream(raw);
		std::string token;

		if (std::getline(stream, token, ':'))
		{
			command.name = token;
		}

		while (std::getline(stream, token, ':'))
		{
			command.args.emplace_back(token);
		}

		return command;
	}
}