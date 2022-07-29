#ifndef __MATRIX_ANALYSIS_H__
#define __MATRIX_ANALYSIS_H__
#include <stdbool.h>

#ifndef __SAMPLE_MAIN_H__
#ifdef _WIN32
#include ".\..\sample.h"
#include ".\matriceDisplay.h"
#elif __linux__
#include "./../sample.h"
#include "./../matriceDisplay.h"
#endif
#endif

int verifyMatrixSize(
  int row_count,
  int column_count,
  int matrix[MAX_ROW_COUNT][MAX_ROW_COUNT];
);

#endif