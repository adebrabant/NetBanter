#include "fsms/ExitState.hpp"
#include "fsms/State.hpp"
#include <memory>

namespace ChatClient
{
	std::unique_ptr<State> ExitState::onProcess()
	{
		return std::unique_ptr<State>();
	}
}