#pragma once
#include "fsms/State.hpp"
#include <memory>
#include <utility>

namespace ChatClient
{
	class StateMachine
	{
	public:
		StateMachine() = default;
		~StateMachine() = default;
		void run();
		template <typename TState, typename... Args>
		void moveToState(Args&&... args);

	private:
		std::unique_ptr<State> m_currentState;
	};

	template<typename TState, typename ...Args>
	inline void StateMachine::moveToState(Args && ...args)
	{
		m_currentState = std::make_unique<TState>(std::forward<Args>(args)...);
	}
}