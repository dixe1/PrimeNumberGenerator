#include "Logger.h"
#include <iostream>
#include <string>

namespace Logger
{
	void log(const std::string& message, LogLevel level = LogLevel::INFO)
	{
		switch (level)
		{
		case LogLevel::INFO:
			std::cout << "[INFO]: " << message << std::endl;
			break;
		case LogLevel::WARNING:
			std::cerr << "[WARNING]: " << message << std::endl;
			break;
		case LogLevel::ERROR:
			std::cerr << "[ERROR]: " << message << std::endl;
			break;
		}
	}

	void INFO(const std::string& message) { log(message, LogLevel::INFO); };
	void WARNING(const std::string& message) { log(message, LogLevel::WARNING); };
	void ERROR(const std::string& message) { log(message, LogLevel::ERROR); };
}// namespace Logger