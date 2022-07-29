#ifndef __IS_MAGIC_SQUARE_H__
#define __IS_MAGIC_SQUARE_H__
#include <stdbool.h>

#ifndef __SAMPLE_MAIN_H__
#ifdef _WIN32
#include ".\..\sample.h"
#elif __linux__
#include "./../sample.h"
#endif
#endif


int getRowSum(
    int row_count,
    int matrix_row[MAX_ROW_COUNT]
);

int getColumnSum(
    int row_count,
    int given_column,
    int matrix[MAX_ROW_COUNT][MAX_ROW_COUNT]
);

int getDiagonalSum(
    int row_count,
    int matrix[MAX_ROW_COUNT][MAX_ROW_COUNT]);

int isMagicSquareBruteForce(
  int row_count,
  int matrix[MAX_ROW_COUNT][MAX_ROW_COUNT]
);

#endif
