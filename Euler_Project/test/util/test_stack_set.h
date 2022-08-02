#ifndef __TEST_EULER_PROJECT_STACK_H__
#define __TEST_EULER_PROJECT_STACK_H__
#ifdef _WIN32
#include ".\..\test.h"
#include ".\..\..\src\util\stack_set.h"
#elif __linux__
#include "./../test.h"
#include "./../../src/util/stack_set.h"
#endif



void stack_set_test_suite();

void linked_list_test_suite();


void test_1_FILO_stack_evaluation();
void test_2_FIFO_stack_evaluation();
void test_3_general_stack_evaluation();



#endif
