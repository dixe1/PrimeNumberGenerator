#include "Includes.hpp"

// cpp 17

int main()
{
	// Getting system information
	SystemInfo info = SystemInfoProvider::get();

	// Example usage of Logger and SystemInfoProvider
	Logger::consoleLoggingEnabled = true;
	Logger::INFO("Application started with " + std::to_string(info.threads) + " threads available.");
	Logger::INFO("Operating System: " + SystemInfoProvider::getOSNameString(info.osName));
}

// Template from: https://github.com/dixe1/cpp-project-template
