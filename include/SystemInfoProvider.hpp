#pragma once
#include <string>
#include <cstdint>

enum class OSName
{
	WINDOWS,
	LINUX
};

struct SystemInfo
{
	uint32_t threadsCount;
	OSName osName;
};

namespace SystemInfoProvider
{
	SystemInfo get();
	std::string getOSNameString(const OSName&);
} // namespace SystemInfoProvider
