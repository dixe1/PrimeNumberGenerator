#include <iostream>
#include "SystemInfoProvider.h"

int main()
{
	SystemInfo info = SystemInfoProvider::get();

	std::cout << "Number of CPU threads: " << info.threads << std::endl;
}