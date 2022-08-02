#ifndef __EUL__PROJ_TWO_H__
#define __EUL__PROJ_TWO_H__

#ifdef _WIN32
#include ".\..\util\base.h"
#elif __linux__
#include "./../util/base.h"
#endif

int project_2();
int project_two_test();
int sumFibonacciEvensInRange(int max_number);
int nextFibonacciNumber(int current_value, int previous_value);


#endif
