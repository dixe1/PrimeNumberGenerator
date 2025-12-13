#include "Logger.h"
#include "SystemInfoProvider.h"

// cpp 17

int main()
{
	// Getting system information
	SystemInfo info = SystemInfoProvider::get();

	// Enable logging usage
	Logger::consoleLoggingEnabled = true;
	Logger::INFO("Application started with " + std::to_string(info.threads) + " threads available.");
	Logger::INFO("Operating System: " + SystemInfoProvider::getOSNameString(info.osName));
}