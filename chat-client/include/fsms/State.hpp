#pragma once

#include <memory>

namespace ChatClient
{
	class State
	{
	public:
		virtual ~State() = default;
		virtual std::unique_ptr<State> onProcess() = 0;
	};
}