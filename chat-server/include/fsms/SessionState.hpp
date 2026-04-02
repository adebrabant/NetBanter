#pragma once

namespace ChatServer
{
	class SessionState
	{
	public:
		virtual ~SessionState() = default;
		virtual void process() = 0;
	};
}