#ifndef __PRIME_UTIL_H__
#define __PRIME_UTIL_H__

#include "base.h"

#ifdef _WIN32
#elif __linux__
#endif


bool setPrimeList(int * prime_list, int array_length, int start, int end);
int findNextPrimeNumber(int current_prime_number);
bool brute_force_prime(int integer);
bool isPrime(int integer);


#endif
