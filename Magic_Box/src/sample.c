#ifndef __MAGIC_BOX_APP_H__
#define __MAGIC_BOX_APP_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
#include ".\sample.h"
#include ".\util\matrixAnalysis.h"
#include ".\util\isMagicSquare.h"
#include ".\..\test\data\test_data.h"
#elif __linux__
#include "./sample.h"
#include "./util/matrixAnalysis.h"
#include "./util/isMagicSquare.h"
#include "./../test/data/test_data.h"
#endif
#endif


void endProgramFunc(int isSuccessful){
  if (isSuccessful){
    printf("\n\nThe matrix provided is a magic square.\nCongradulations!\n\n");
  } else {
    printf("\n\nThe matrix provided is not a magic square.");
  }
  printf("\n\n----------Terminating Evaulation of Matrix----------\n\n");
}


int main()
{
/*        //// ACCEPTS MATRICES UP TO DIMENSION OF :  150 x 150        */

  printf("\n\n----------Beginning Evaulation if Matrix is a Magic Square----------\n\n");
  

  int matrix_is_square;
  int matrix_is_magic_square;

  int expected_matrix[EXPECTED_MATRIX_ROW_COUNT][EXPECTED_MATRIX_ROW_COUNT] = {0};
  
  int expected_row_count = 4;
  int expected_column_count = 4;

    //// If you manually insert a candidate matrix in expected_matrix = {{x,y,...,z},{q,r,...s},...{a,b,...,c}};
      //    the code will directly process that.

  if (expected_matrix[0][0] == 0){
    for (int i=0; i<expected_row_count; i++){
      for (int j=0; j<expected_column_count;j++){
        /*           _________Replace Matrix Below w/ Sample ________     */
        // expected_matrix[i][j] = magic3x3Matrix[i][j];
        // expected_matrix[i][j] = basic3x3Matrix[i][j];
        expected_matrix[i][j] = magic4x4Matrix[i][j];
      }
    }
  } else {
    for(int i=0; i<EXPECTED_MATRIX_ROW_COUNT; i++)
    {
      for(int j=0; j<EXPECTED_MATRIX_ROW_COUNT; j++){
        if(expected_matrix[i][j] == 0)
          break;
        expected_column_count = j+1; /// finding outter most limit of rows & columns
      }
      if(expected_matrix[i][0] == 0)
        break;
      expected_row_count = i+1; 
    }
  }

  matrix_is_square = verifyMatrixSize(expected_row_count,expected_column_count,expected_matrix);
  
  if (abs(matrix_is_square-1)){
    endProgramFunc(0);
    return 0;
  }
  
  matrix_is_magic_square = isMagicSquareBruteForce(expected_row_count, expected_matrix);

  if (abs(matrix_is_magic_square-1)){
    endProgramFunc(0);
    return 0;
  }

  /// Matrix did not fail deductive battery.
  endProgramFunc(1);

  return 0;
}
