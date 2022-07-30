#ifndef __TEST_APP_BASE_H__
#define __TEST_APP_BASE_H__
#include <stdio.h>
#include <stdbool.h>

#ifndef __SAMPLE_MAIN_H__
#ifdef _WIN32
#include ".\..\src\project\base.h"
#elif __linux__
#include "./../src/project/base.h"
#endif
#endif


void runTest(bool condition, char method_tested[], char test_case[], bool * test_passed);
void testResult(char test_name[], bool test_passed);




#endif
