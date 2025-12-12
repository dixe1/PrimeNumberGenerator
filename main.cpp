#include "Logger.h"
#include "SystemInfoProvider.h"

// cpp 17

int main()
{
	// Getting system information
	SystemInfo info = SystemInfoProvider::get();

	/*
	* Example usage for Logger
	* 
	Logger::INFO("info message");
	Logger::WARNING("warning message");
	Logger::ERROR("error message");
	*/

}