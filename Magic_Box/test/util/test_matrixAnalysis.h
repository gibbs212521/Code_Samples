#ifndef __TEST_MATRIX_READER_H__
#define __TEST_MATRIX_READER_H__
#ifdef _WIN32
#include ".\..\test.h"
#elif __linux__
#include "./../test.h"
#endif

void matrix_test_suite();
void test_1_test_multiple_matrice_sizes();
void test_2_test_detect_if_square();
void test_3_test_for_data_loss();
void test_4_test_stats_recover();

#endif
