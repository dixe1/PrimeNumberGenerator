#pragma once

struct SystemInfo
{
	int threads;
};

namespace SystemInfoProvider
{
	SystemInfo get();
} // namespace SystemInfoProvider