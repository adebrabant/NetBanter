#pragma once
#include "fsms/SessionState.hpp"
#include <memory>
#include <utility>
#include <vector>
#include <type_traits>

namespace ChatServer
{
	class SessionStateMachine
	{
	public:
		SessionStateMachine();
		~SessionStateMachine() = default;
		void run();
		template <typename TState>
		void moveToState();
		template <typename TState, typename... Args>
		void addState(Args&&... args);

	private:
		std::vector<std::unique_ptr<SessionState>> m_states;
	    SessionState* m_currentState;
	};

	template<typename TState>
	inline void SessionStateMachine::moveToState()
	{
		static_assert(std::is_base_of<SessionState, TState>::value, "TState must derive from SessionState");

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
	inline void SessionStateMachine::addState(Args && ...args)
	{
		static_assert(std::is_base_of<SessionState, TState>::value, "TState must derive from State");
		m_states.emplace_back(std::make_unique<TState>(std::forward<Args>(args)...));
	}
}