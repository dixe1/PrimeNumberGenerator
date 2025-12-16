#include "Logger.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <iomanip>

namespace Logger
{
	std::tm getLocalTime()
	{
		std::time_t t = std::time(nullptr);
		std::tm now{};

	#if defined(_WIN32) || defined(_WIN64)
		localtime_s(&now, &t);
	#else
		localtime_r(&t, &now);
	#endif

		return now;
	}

	static std::string getLogLevelString(const LogLevel level)
	{
		switch (level)
		{
		case LogLevel::INFO:
			return " [INFO]: ";
		case LogLevel::WARNING:
			return " [WARNING]: ";
		case LogLevel::ERROR:
			return " [ERROR]: ";
		case LogLevel::DEBUG:
			return " [DEBUG]: ";
		default:
			return " [UNKNOWN]: ";
		}
	}

	static void log(const std::string& message, const LogLevel logLvl)
	{
		std::string stringMessage = getLogLevelString(logLvl);

		// Ensure the logs directory and file exists
		std::filesystem::path folderPath = "logs";
		if (!std::filesystem::exists(folderPath)) std::filesystem::create_directory(folderPath);
		std::ofstream logFile(folderPath / "application.log", std::ios::app);

		// Get current time
		std::tm time_ = getLocalTime();

		// Log to console
		if(consoleLoggingEnabled) std::cout << std::put_time(&time_, "[ %H:%M:%S ]") << stringMessage << message << std::endl;

		// Log to file
		logFile << std::put_time(&time_, "[ %Y:%m:%d ] [ %H:%M:%S ]") << stringMessage << message << std::endl;
	}

	void INFO(const std::string& message) { log(message, LogLevel::INFO); }
	void WARNING(const std::string& message) { log(message, LogLevel::WARNING); }
	void ERROR(const std::string& message) { log(message, LogLevel::ERROR); }
	void DEBUG(const std::string& message) { log(message, LogLevel::DEBUG); }
}// namespace Logger
