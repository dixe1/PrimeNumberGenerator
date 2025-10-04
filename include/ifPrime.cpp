#include "ifPrime.h"
#include <math.h>

bool ifPrime(long long& n) {
    double sq{ sqrt(n) };
    for (long long i = 2; i <= sq; i++) {
        if (n % i == 0) return false;
    }
    return true;
}