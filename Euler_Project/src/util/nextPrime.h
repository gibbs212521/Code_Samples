#ifndef __NEXT_PRIME_UTIL_H__
#define __NEXT_PRIME_UTIL_H__
#ifdef _WIN32
#include ".\base.h"
#elif __linux__
#include "./base.h"
#endif


int findNextPrimeNumber(int current_prime_number);

#endif
