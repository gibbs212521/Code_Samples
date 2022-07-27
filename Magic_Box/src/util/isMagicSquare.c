#ifndef __SAMPLE_MAIN_H__
#ifdef _WIN32
#include ".\isMagicSquare.h"
#elif __linux__
#include "./isMagicSquare.h"
#endif
#endif

/// Used in Brute Force Method

int getRowSum(
    int row_count,
    int matrix_row[EXPECTED_MATRIX_ROW_COUNT]
){
  int row_sum = 0;
  for (int i=0; i<row_count; i++)
    row_sum += matrix_row[i];
  return row_sum;
}

int getColumnSum(
    int row_count,
    int given_column,
    int matrix[EXPECTED_MATRIX_ROW_COUNT][EXPECTED_MATRIX_ROW_COUNT]
){
  int column_sum = 0;
  for (int i=0; i<row_count; i++)
    column_sum += matrix[i][given_column];
  return column_sum;
}

int getDiagnalSum(
    int row_count,
    int matrix[EXPECTED_MATRIX_ROW_COUNT][EXPECTED_MATRIX_ROW_COUNT]
){
    int left_sum = 0;
    int right_sum = 0;
    for (int k=0; k<row_count; k++){
      left_sum += matrix[k][k];
      right_sum += matrix[k][row_count-1-k];
  }
  if (left_sum != right_sum)
    return -1;
  return right_sum;
}

int isMagicSquareBruteForce(
  /// Boolean result
  int row_count,
  int matrix[EXPECTED_MATRIX_ROW_COUNT][EXPECTED_MATRIX_ROW_COUNT]
){
  // Initital Evaluations
  int init_row_result, init_column_result;
  int row_result, column_result;
  int diagonal_result = getDiagnalSum(row_count, matrix);
  if (diagonal_result == -1)
    return 0;
  init_row_result = getRowSum(row_count,matrix[0]);
  init_column_result = getColumnSum(row_count,0,matrix);
  if ((diagonal_result != init_row_result) || (diagonal_result != init_column_result))
    return 0;
  for (int k=1; k<row_count; k++){
    row_result = getRowSum(row_count,matrix[k]);
    column_result = getColumnSum(row_count,k,matrix);
    if ((row_result != init_row_result) || (column_result != init_column_result))
      return 0;
  }
  return 1;
}
