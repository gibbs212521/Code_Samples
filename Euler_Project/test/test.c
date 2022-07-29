#include "test.h"

void runTest(bool condition, char class_method[], char test_case[], bool * ptest_passed)
{
    if(condition == true)
        printf("\t %s \t %s \t PASSED\n",class_method, test_case);
    else
    {
        printf("\n\n\n\t %s \t %s \t FAILED\n",class_method, test_case);
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
