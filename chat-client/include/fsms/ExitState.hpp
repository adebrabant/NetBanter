#pragma once

#include "fsms/State.hpp"
#include <memory>

namespace ChatClient
{
	class ExitState : public State
	{
	public:
		ExitState() = default;
		std::unique_ptr<State> onProcess() override;
	};
}