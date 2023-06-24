#ifndef __PRIME_UTIL_H__
#define __PRIME_UTIL_H__

#include "base.h"
#include "stdint.h"

#ifdef _WIN32
#elif __linux__
#endif


bool setPrimeList(int * prime_list, int array_length, long start, long end);
long findNextPrimeNumber(long current_prime_number);
bool brute_force_prime(long integer);
bool isPrime(long integer);

bool setPrimeListUint(unsigned long * prime_list, unsigned long array_length);
bool brute_force_prime_uint(unsigned long integer);
bool isPrimeUint(unsigned long integer);

#endif
