#include <string>
#pragma once

enum class OSName
{
	WINDOWS,
	LINUX
};

struct SystemInfo
{
	uint32_t threads;
	OSName osName;
};

namespace SystemInfoProvider
{
	SystemInfo get();
	std::string getOSNameString(const OSName&);
} // namespace SystemInfoProvider