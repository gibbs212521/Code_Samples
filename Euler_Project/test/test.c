#include "test.h"


void runTest(bool condition, char method_tested[], char test_case[], bool * ptest_passed)
{
    if(condition == true)
        printf("   %s \t %s \t PASSED\n",method_tested, test_case);
    else
    {
        printf("\n\n\n   %s \t %s \t FAILED\n",method_tested, test_case);
        *ptest_passed = false;
    }
}


void testResult(char test_name[], bool test_passed)
{
    char dotted_line[120] = " --------------------------------------------------------------------------------------------------------------";
    char Xed_row[120] =    "  X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X ";
    if(test_passed==true){
        printf("%s\n",dotted_line);
        printf("\t\t\t\t\t\t\t\t\t PASSED    %s\n%s\n", test_name, dotted_line);
    } else {
        printf("\n%s\n%s\n",dotted_line, Xed_row);
        printf("\t\t\t\t\t\t\t\t\t FAILED    %s\n%s\n%s\n\n", test_name, Xed_row, dotted_line);
    }
}
