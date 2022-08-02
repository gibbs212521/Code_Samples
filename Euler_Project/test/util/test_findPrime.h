#ifndef __TEST_PRIME_UTIL_H__
#define __TEST_PRIME_UTIL_H__
#ifdef _WIN32
#include ".\..\test.h"
#include ".\..\..\src\util\findPrime.h"
#elif __linux__
#include "./../test.h"
#include "./../../src/util/findPrime.h"
#endif


void prime_test_suite();


void test_1_is_number_prime();
void test_2_find_next_prime();
void test_3_list_out_primes();
void test_4_follows_prime_trends();





#endif
