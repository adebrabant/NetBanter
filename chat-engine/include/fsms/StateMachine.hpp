#pragma once

#include "states/State.hpp"
#include <memory>
#include <utility>
#include <vector>
#include <type_traits>

namespace ChatEngine
{
	class StateMachine
	{
	public:
		StateMachine();
		~StateMachine() = default;
		void run();
		template <typename TState>
		void moveToState();
		template <typename TState, typename... Args>
		void addState(Args&&... args);

	private:
		std::vector<std::unique_ptr<State>> m_states;
	    State* m_currentState;
	};

	template<typename TState>
	inline void StateMachine::moveToState()
	{
		static_assert(std::is_base_of<State, TState>::value, "TState must derive from State");

		for (auto& state : m_states)
		{
			if (auto casted = dynamic_cast<TState*>(state.get()))
			{
				m_currentState = casted;
				return;
			}
		}

		m_currentState = nullptr; 
	}

	template<typename TState, typename ...Args>
	inline void StateMachine::addState(Args && ...args)
	{
		static_assert(std::is_base_of<State, TState>::value, "TState must derive from State");
		m_states.emplace_back(std::make_unique<TState>(std::forward<Args>(args)...));
	}
}