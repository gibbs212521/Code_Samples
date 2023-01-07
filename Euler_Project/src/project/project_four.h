#ifndef __EUL__PROJ_THREE_H__
#define __EUL__PROJ_THREE_H__

#ifdef _WIN32
#include ".\..\util\base.h"
#include ".\..\util\findPrime.h"
#include ".\..\util\findFactors.h"
#elif __linux__
#include "./../util/base.h"
#include "./../util/findPrime.h"
#include "./../util/findFactors.h"
#endif

/*
A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
int project_3();
int project_three_test();

int getMaxPrimeFactor(stack_handle * stack, int value);
int getPrimeFactors(stack_handle * stack, int value);

#endif
