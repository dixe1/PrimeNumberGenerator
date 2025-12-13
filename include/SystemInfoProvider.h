#include <string>
#pragma once

enum class OSName
{
	WINDOWS,
	LINUX
};

struct SystemInfo
{
	int threads;
	OSName osName;
};

namespace SystemInfoProvider
{
	SystemInfo get();
	std::string getOSNameString(OSName);
} // namespace SystemInfoProvider