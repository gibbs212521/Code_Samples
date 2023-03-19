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
void comboProdBuild(int max_var, int * product_array, int array_depth);

#endif
