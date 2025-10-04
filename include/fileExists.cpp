#include "fileExists.h"
#include <fstream>

bool fileExists() {
    std::ifstream file("primeNumbers.txt");
    return file.is_open();
}