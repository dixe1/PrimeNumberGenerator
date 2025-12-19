# ProjectTemplate
A C++17 project template with a Logger module and SystemInfoProvider for quickly starting new projects.

## Note on Module Dependencies
- `SystemInfoProvider.hpp/cpp` require `Logger.hpp/cpp`.

## Build

### 1. Clone the repository
```bash
git clone https://github.com/dixe1/cpp-project-template
cd cpp-project-template
```

### 2. Build Project

#### For Visual Studio 2022:
```bash
cmake -G "Visual Studio 17 2022" -A x64 . -B build
```

#### For Visual Studio 2019:
```bash
cmake -G "Visual Studio 16 2019" -A x64 . -B build
```

#### For Linux / macOS (Unix Makefiles):
```bash
cmake -G "Unix Makefiles" -B build
cmake --build build
```


## Example usage

### Logger
```cpp
#include "Logger.hpp"

int main()
{
  Logger::consoleLoggingEnabled = true;

  Logger::INFO("This is a info");
  Logger::WARNING("This is a warning");
  Logger::ERROR("This is an error");
  Logger::DEBUG("This is a debug");
}
```

### SystemInfoProvider
```cpp
#include "SystemInfoProvider.hpp"
#include <iostream>

int main()
{
  SystemInfo info = SystemInfoProvider::get();
  std::cout << "CPU threads detected: " << info.threads << "\n";
  std::cout << "Operating System: " << SystemInfoProvider::getOSNameString(info.osName) << "\n";
}
