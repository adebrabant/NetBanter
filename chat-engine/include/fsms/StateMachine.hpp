#pragma once

#include "states/State.hpp"

#include <unordered_map>
#include <memory>
#include <utility>
#include <vector>
#include <typeindex>
#include <type_traits>
#include <stdexcept> 

namespace ChatEngine
{
	class StateMachine
	{
	public:
		StateMachine();
		~StateMachine() = default;
		void run();
		void exit();
		template <typename TState>
		void moveToState();
		template <typename TState, typename... Args>
		void addState(Args&&... args);
		template <typename TState>
		TState* getState();

	private:
		std::unordered_map<std::type_index, std::unique_ptr<ChatEngine::State>> m_states;
	    ChatEngine::State* m_currentState;
	};

	template<typename TState>
	inline void StateMachine::moveToState()
	{
		m_currentState = getState<TState>();
	}

	template<typename TState, typename ...Args>
	inline void StateMachine::addState(Args && ...args)
	{
		static_assert(std::is_base_of<State, TState>::value, "TState must derive from State");
		m_states[typeid(TState)] = std::make_unique<TState>(std::forward<Args>(args)...);
	}

	template <typename TState>
	inline TState* StateMachine::getState()
	{
		static_assert(std::is_base_of<State, TState>::value, "TState must derive from State");

		auto it = m_states.find(typeid(TState));
		if (it == m_states.end())
		{
			throw std::runtime_error("State not found");
		}

		return static_cast<TState*>(it->second.get());
	}
}