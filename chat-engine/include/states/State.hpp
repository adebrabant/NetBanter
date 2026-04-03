#pragma once

namespace ChatEngine
{
	class StateMachine;

	class State
	{
	public:
		State(StateMachine& stateMachine) :
			m_stateMachine(stateMachine)
		{

		}

		virtual ~State() = default;
		virtual void handle() = 0;

	protected:
		StateMachine& m_stateMachine;
	};
}