#ifndef __SAMPLE_MAIN_H__
#ifdef _WIN32
#include ".\matriceDisplay.h"
#elif __linux__
#include "./matriceDisplay.h"
#endif
#endif


void display(int row_count, int column_count, int matrix[EXPECTED_MATRIX_ROW_COUNT][EXPECTED_MATRIX_ROW_COUNT])
{
  //// Simple function to make matrices visible
  printf("row : %d \ncol : %d \n\n", row_count, column_count);
  for(int i=0; i<row_count; i++)
  {
    for(int j=0; j<column_count; j++){
      if(matrix[i][j] == 0)
        break;
      printf("\t%d",matrix[i][j]);
    }
    if(matrix[i][0] == 0)
      break;
    printf("\n"); 
  }
}

