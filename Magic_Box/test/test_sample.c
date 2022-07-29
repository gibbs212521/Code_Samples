#ifdef _WIN32
#include ".\data\test_data.h"
#include ".\util\test_isMagicSquare.h"
#include ".\util\test_matrixAnalysis.h"
#include ".\util\test_matrixGenerator.h"
#include ".\..\src\sample.h"
#include ".\..\src\util\matriceDisplay.h"
#elif __linux__
#include "./data/test_data.h"
#include "./util/test_isMagicSquare.h"
#include "./util/test_matrixAnalysis.h"
#include "./util/test_matrixGenerator.h"
#include "./../src/sample.h"
#include "./../src/util/"
#endif

#include <stdio.h>
#include <stdlib.h>


// int main(int argc, char *argv[])
int main()
{
  
/*        //// ACCEPTS MATRICES UP TO DIMENSION OF :  150 x 150        */
/// CURRENTLY NO INPUT PARAMETERS



  /// TODO: Return to this code for further kata development

  // printf("inputs %d\n", argc);
  // printf("straight %s\n\n", argv[1]);
  // printf("%s * 5 = %d \n\n", argv[1], atoi(argv[1]) * 5);
  // printf(argv[2]);
  // printf("\n\n");
  
  // char * input_num = argv[1];
  // // char input_const = argv[1];
  // printf("by pointer %s\n\n", input_num);
  // // printf("by const %s\n\n", input_const);  // failed 
  // // printf("by array %s\n\n", argv[1][0]);  // failed

  // int *next_value;

  // char * e, * err_f;
  // int expected_row_count = strtol(argv[1], &e, 0);
  // printf("size of ascii : %d\nsize of int-l : %d", sizeof(argv[1]), sizeof(expected_row_count));

  // int expected_column_count = strtol(argv[1], &e, 0);
  // if (*e != '\0'){
  //   printf(e);
  //   printf("error here\n");
  // } else {
  //   printf(e);
  //   printf("no error here\n");
  // }
  // printf("%s\n\n", argv[1]);
  // printf("expected row count a: %d\n\n", expected_column_count);
  // printf("expected row count b: %d\n\n", expected_row_count);
  // printf("%s\n\n", argv[1]);
  // int expected_matrix[MAX_ROW_COUNT][MAX_ROW_COUNT] = {0};
  // int expected_matrix[3][3] = {0};
  


  // int skipper_value = 0;
  // printf("hello\n");

  // for (int k=0; k<3; k++){
  //   printf("hello-");

  //   next_value = strtol(argv[2], &e, 0);    
  //   if (*e != '\0'){
  //     printf(e);

  //     printf("error here\n");
  //     printf(e[0]);

  //     printf("%d", strtol(e[0], &err_f, 0));
  //     if (*err_f != '\0'){
  //       printf("\nnext_err");
  //       printf(err_f);
  //     }else {
  //       printf("\n What not err");
  //     }
  //   } else {
  //     printf(e);
  //     printf("no error here-");
  //     printf("%d", next_value);
  //   }
  //   printf("\n%d", next_value);
  // }
  

  // for (int i=0; i<expected_row_count; i++){
  //   for (int j=0; j<expected_row_count;j++){
  //     printf("array status: %s", expected_row_count);
  //     /*           _________Replace Matrix Below w/ Sample ________     */
  //     while (10 < atoi(argv[2][i+j+skipper_value]) & atoi(argv[2][i+j+skipper_value]) < 0)
  //     {
  //       printf(argv[2][i+j+skipper_value]);
  //       skipper_value++;
  //     }
  //     expected_matrix[i][j] = atoi(argv[2][i+j+skipper_value]);
  //     // expected_matrix[i][j] = magic3x3Matrix[i][j];
  //   }
  //   printf("\n");
  // }
  // display(3,3,expected_matrix);
}

