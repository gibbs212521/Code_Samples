#ifndef __TEST_PALINDROMES_UTIL_H__
#define __TEST_PALINDROMES_UTIL_H__
#ifdef _WIN32
#include ".\..\test.h"
#include ".\..\..\src\util\findPalindrome.h"
#elif __linux__
#include "./../test.h"
#include "./../../src/util/findPalindrome.h"
#endif



void palindrome_test_suite();

void test_1_is_palindrome();




#endif
