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
    if(test_passed==true)
        printf("\t\t\t\t\t\t\t\t\t PASSED    %s\n", test_name);
    else
        printf("\t\t\t\t\t\t\t\t\t FAILED    %s\n\n\n\n", test_name);
}
