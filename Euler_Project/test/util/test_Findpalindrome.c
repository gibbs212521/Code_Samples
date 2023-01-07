#include "test_findPalindrome.h"

void palindrome_test_suite()
{
    test_1_is_palindrome();
}

long long known_palindrome_array[25] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 12021,\
    56489598465, 123456789987654321, 98765432123456789, 111111111, 11112221111,\
    543222345, 151, 1551, 100001, 393, 9932399, 241142, 7142417, 3242423};

long long known_not_palindrome_array[25] = {1,2,3,4,5,6,7,8,9,0,10,20,102,32424233,15,\
    98765332123456789, 111111121, 31112221111};

void test_1_is_palindrome(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "Is Palindrome Number Test";

    /// CASE 1
//  char _t_guide_[30] = "                             "
    char test_case[30] = "Compare to Known Palindromes ";
//  char _method_guide[30] = "                         ";
    char method_tested[30] = "isPalindrome function    ";
    condition = true;
    bool conditional = true;
    for (int i=0; i<25; i++)
    {
        conditional = isPalindrome(known_palindrome_array[i]);
        condition = (condition && conditional);
        if (abs(conditional-1))
            printf("\n\t%lld claimed to not be a plaindrome", known_palindrome_array[i]);
    }
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 2
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Compare to Non-Palindromes   ");
    strcpy(method_tested,"isPalindrome function    ");
    condition = true;
    for (int i=0; i<25; i++)
    {
        conditional = abs(isPalindrome(known_not_palindrome_array[i])-1);
        condition = (condition && conditional);
        if (abs(conditional-1))
            printf("\n\t%d claimed to be a plaindrome", known_not_palindrome_array[i]);
    }
    runTest(condition, method_tested, test_case, &test_passed);

    testResult(test_name,test_passed);
}

