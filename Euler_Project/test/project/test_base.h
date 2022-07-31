#ifndef __TST_project_H__
#define __TST_project_H__
#ifdef _WIN32
#include ".\..\test.h"
#include ".\..\..\src\util\base.h"
#elif __linux__
#include "./../test.h"
#include "./../../src/util/base.h"
#endif

#include <string.h>


void base_test_suite();

void linked_list_test_suite();


void test_1_FILO_stack_evaluation();
void test_2_FIFO_stack_evaluation();
void test_3_general_stack_evaluation();



#endif
