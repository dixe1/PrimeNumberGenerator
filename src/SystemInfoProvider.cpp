#include "Logger.hpp"
#include "SystemInfoProvider.hpp"
#include <iostream>
#include <thread>
#include <string>

namespace SystemInfoProvider
{
	SystemInfo get()
	{
		// Detect number of threads
		uint32_t threads{ std::thread::hardware_concurrency() };
		if(threads == 0 || threads == UINT32_MAX)
		{
			threads = 1; // set to 1 if unable to detect
			Logger::WARNING("Unable to detect number of hardware threads, defaulting to 1.");
		}

		// Detect OS
		#if defined(_WIN32) || defined(_WIN64)
		OSName os = OSName::WINDOWS;
		#else
		OSName os = OSName::LINUX;
		#endif

		return SystemInfo{ threads,os };
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