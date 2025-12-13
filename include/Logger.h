#include <string>
#pragma once

enum class LogLevel
{
	INFO,
	WARNING,
	ERROR
};

namespace Logger
{
	inline bool consoleLoggingEnabled = false;

	void INFO(const std::string&);
	void WARNING(const std::string&);
	void ERROR(const std::string&);
}// namespace Logger