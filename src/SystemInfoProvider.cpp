#include "Logger.hpp"
#include "SystemInfoProvider.hpp"
#include <thread>
#include <string>

namespace SystemInfoProvider
{
	SystemInfo get()
	{
		// Detect number of threads
		uint32_t threadsCount{ std::thread::hardware_concurrency() };
		if(threadsCount == 0)
		{
			threadsCount = 1; // set to 1 if unable to detect
			Logger::WARNING("Unable to detect number of hardware threads, defaulting to 1.");
		}

		// Detect OS
		#if defined(_WIN32) || defined(_WIN64)
		OSName osName = OSName::WINDOWS;
		#else
		OSName osName = OSName::LINUX;
		#endif

		return SystemInfo{ threadsCount,osName };
	}

	std::string getOSNameString(const OSName& os)
	{
		switch (os)
		{
		case OSName::WINDOWS:
			return "Windows";
		case OSName::LINUX:
			return "Linux";
		default:
			return "Unknown";
		}
	}
} // namespace SystemInfoProvider
