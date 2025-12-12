#include "SystemInfoProvider.h"
#include <thread>
#include <iostream>

namespace SystemInfoProvider
{
	SystemInfo get()
	{
		int threads = std::thread::hardware_concurrency();
		if(threads <= 0)
		{
			threads = 1; // set to 1 if unable to detect
			std::cerr << "Warning: Unable to detect number of CPU threads, defaulting to 1." << std::endl;
		}

		return { threads };
	}
} // namespace SystemInfoProvider