#ifndef __EUL__PROJ_ONE_H__
#define __EUL__PROJ_ONE_H__

#ifdef _WIN32
#include ".\..\util\stack_set.h"
#include ".\..\util\findPrime.h"
#elif __linux__
#include "./../util/stack_set.h"
#include "./../util/findPrime.h"
#endif


int project_one_test();
int project_1(int factor_one, int factor_two, int max_number);
int sumProductsInRange(int factor_one, int factor_two, int range);
int sumPrimeNumbersInRange(int start, int end);

#endif
