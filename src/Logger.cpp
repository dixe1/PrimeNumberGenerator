#include "Logger.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <iomanip>

namespace Logger
{

	static void log(const std::string& message, const LogLevel& level = LogLevel::INFO)
	{
		// Ensure the logs directory and file exists
		std::filesystem::path folderPath = "logs";
		if (!std::filesystem::exists(folderPath)) std::filesystem::create_directory(folderPath);
		std::ofstream logFile(folderPath / "application.log", std::ios::app);

		// Get current time
		std::time_t t = std::time(nullptr);
		std::tm* now = std::localtime(&t);

		logFile << std::endl;

		// Stupid long switch case for logging levels
		switch (level)
		{
		case LogLevel::INFO:
			// Log to console
			if(consoleLoggingEnabled) std::cout << std::put_time(now, "[ %H:%M:%S ]") << "[INFO]: " << message << std::endl;

			// Log to file
			logFile << std::put_time(now, "[ %Y:%m:%d ] [ %H:%M:%S ]") << "[INFO]: " << message << std::endl;
			break;
		case LogLevel::WARNING:
			// Log to console
			if (consoleLoggingEnabled) std::cout << std::put_time(now, "[ %H:%M:%S ]") << "[WARNING]: " << message << std::endl;

			//log to file
			logFile << std::put_time(now, "[ %Y:%m:%d ] [ %H:%M:%S ]") << "[WARNING]: " << message << std::endl;
			break;
		case LogLevel::ERROR:
			// Log to console
			if (consoleLoggingEnabled) std::cout << std::put_time(now, "[ %H:%M:%S ]") << "[ERROR]: " << message << std::endl;

			// Log to file
			logFile << std::put_time(now, "[ %Y:%m:%d ] [ %H:%M:%S ]") << "[ERROR]: " << message << std::endl;
			break;
		case LogLevel::DEBUG:
			// Log to console
			if (consoleLoggingEnabled) std::cout << std::put_time(now, "[ %H:%M:%S ]") << "[DEBUG]: " << message << std::endl;

			// Log to file
			logFile << std::put_time(now, "[ %Y:%m:%d ] [ %H:%M:%S ]") << "[DEBUG]: " << message << std::endl;
			break;
		}
	}

	void INFO(const std::string& message) { log(message, LogLevel::INFO); }
	void WARNING(const std::string& message) { log(message, LogLevel::WARNING); }
	void ERROR(const std::string& message) { log(message, LogLevel::ERROR); }
	void DEBUG(const std::string& message) { log(message, LogLevel::DEBUG); }
}// namespace Logger