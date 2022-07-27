#ifndef __MATRICE_DISPLAY_H__
#define __MATRICE_DISPLAY_H__

#ifndef __SAMPLE_MAIN_H__
#ifdef _WIN32
#include ".\..\sample.h"
#elif __linux__
#include "./../sample.h"
#endif
#endif

void display(
    int row_count, 
    int column_count, 
    int matrix[EXPECTED_MATRIX_ROW_COUNT][EXPECTED_MATRIX_ROW_COUNT]
);

#endif

// void convertToInteger


