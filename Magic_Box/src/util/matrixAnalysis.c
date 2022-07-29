
#ifndef __SAMPLE_MAIN_H__
#ifdef _WIN32
#include ".\matrixAnalysis.h"
#elif __linux__
#include "./matrixAnalysis.h"
#endif
#endif


int verifyMatrixSize(
  int row_count,
  int column_count,
  int matrix[MAX_ROW_COUNT][MAX_ROW_COUNT]
){
  bool matrix_is_square;
  display(row_count, column_count, matrix);  /// for quick visual testing
  
  int total_matrix_size = 0; // N.B. 4 bytes per integer
  int row_size = sizeof(matrix[0]);
  int element_size = sizeof(matrix[0][0]); // see N.B. above

  column_count = row_size / element_size;

    // Assume Square
  for (int i=0; i<column_count; i++){
    total_matrix_size +=sizeof(matrix[i]);
  }

  row_count = total_matrix_size / row_size;


  /*      Square Matrix Evaluation:     */
  if (row_count == column_count){
    matrix_is_square = true;
  } else {
    matrix_is_square = false;
  }
  
  // display(row_count, column_count, matrix);

  return matrix_is_square;
}
