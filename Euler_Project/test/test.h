#ifndef __TEST_APP_BASE_H__
#define __TEST_APP_BASE_H__
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void runTest(bool condition, char method_tested[], char test_case[], bool * test_passed);
void testResult(char test_name[], bool test_passed);


#endif
