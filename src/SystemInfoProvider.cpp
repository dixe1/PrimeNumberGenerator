#include "Logger.h"
#include "SystemInfoProvider.h"
#include <iostream>
#include <thread>

namespace SystemInfoProvider
{
	SystemInfo get()
	{
		int threads = std::thread::hardware_concurrency();
		if(threads <= 0)
		{
			threads = 1; // set to 1 if unable to detect
			Logger::WARNING("Unable to detect number of hardware threads, defaulting to 1.");
		}

		return { threads };
	}
} // namespace SystemInfoProvider