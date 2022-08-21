#ifndef __TEST_FACTORS_UTIL_H__
#define __TEST_FACTORS_UTIL_H__
#ifdef _WIN32
#include ".\..\test.h"
#include ".\..\..\src\util\findFactors.h"
#elif __linux__
#include "./../test.h"
#include "./../../src/util/findFactors.h"
#endif


void factors_test_suite();

void test_1_is_factor();
void test_2_find_all_factors();
void test_3_is_not_factor();
void test_4_eliminate_all_non_factors();


#endif
