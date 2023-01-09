#ifndef __PALINDROME_UTIL_H__
#define __PALINDROME_UTIL_H__

#include "base.h"
#include "findFactors.h"
#include "stdint.h"

#ifdef _WIN32
#elif __linux__
#endif

bool isPalindrome(long long palindrome_candidate);
long long nextPalindrome(long long current_palindrome);
int * getGreatestMultiplePair(uint64_t palindrome, int max_factor_ten_power, \
    int num_of_factors);

#endif
