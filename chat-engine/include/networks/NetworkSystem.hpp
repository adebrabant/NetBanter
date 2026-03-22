#pragma once

namespace ChatEngine
{
	class NetworkSystem
	{
	public:
		NetworkSystem();
		~NetworkSystem();

		NetworkSystem(const NetworkSystem&) = delete;
		NetworkSystem& operator=(const NetworkSystem&) = delete;
		NetworkSystem(NetworkSystem&&) = delete;
		NetworkSystem& operator=(NetworkSystem&&) = delete;
	};
}