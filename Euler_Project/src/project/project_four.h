#ifndef __EUL__PROJ_FOUR_H__
#define __EUL__PROJ_FOUR_H__

#ifdef _WIN32
#include ".\..\util\base.h"
#include ".\..\util\findPalindrome.h"
#include ".\..\util\findFactors.h"
#elif __linux__
#include "./../util/base.h"
#include "./../util/findPalindrome.h"
#include "./../util/findFactors.h"
#endif

/*
A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

 999 x 999 = 998001
-------------997799  == UTMOST ceiling
1001 x 909 = 919919  == upper ceiling

902 x 909 = 819918 == bottom barrier
101 x 8118


*/
int project_4();
int project_four_test();


#endif
