#pragma once
#include <string>
#include <vector>

namespace ChatEngine
{
	struct Command
	{
		std::string name;
		std::vector<std::string> args;
	};

	// ToDo: Add unit testing to this
	class CommandParser
	{
	public:
		static Command parse(const std::string& raw);
	};
}