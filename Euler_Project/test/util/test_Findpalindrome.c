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

    
    /// CASE 3
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Test All Palindromes         ");
    strcpy(method_tested,"nextPalindrome function  ");
    condition = true;

    long long top_palindrome = 999999;
    long long next_palindrome = top_palindrome;
    
    while (next_palindrome && condition){
        next_palindrome = nextPalindrome(next_palindrome);
        if (next_palindrome==-1){
            condition = true;
            break;
        }
        if (abs(isPalindrome(next_palindrome)-1)){
            printf("%lld is not a palindrome", next_palindrome);
            condition = false;
        };
    }

    /// CASE 4
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Get Palindrome Factors       ");
    strcpy(method_tested,"getGreatestMultiplePair  ");
    condition = true;
    //// additional case required to test boundry conditions where factors exceed maximum factor magnitude.

    /// trivial cases:
    // 1)  99 * 91 = 9009
    // 2) 101 * 99 = 9999
    // 3) 902 x 909 = 819918
    // 4) 919 * 1001 = 919919


    uint64_t palindrome = 919919;
    int * test_arr;
    int indx;


    // trival cases 1 & 2
    /// trivial cases:
    // 1)  99 * 91 = 9009
    int max_ten_power;
    int max_num_of_factors;
    uint64_t provide_palindrome = 9009;
    uint16_t running_product = 1;
   
    max_ten_power = 1;
    max_num_of_factors = 2;
    provide_palindrome = 9009;
    test_arr = getGreatestMultiplePair(provide_palindrome, max_ten_power, \
        max_num_of_factors);
    running_product = 1;
    for (indx=0; indx<max_num_of_factors; indx++){
        running_product *= (uint64_t) test_arr[indx];
        printf("\n%d -- %lu",test_arr[indx], running_product);
    }
    if (running_product != provide_palindrome)
        condition = false;
   
    /// trivial cases:
    // 2) 101 * 99 = 9999
    max_ten_power = 1;
    max_num_of_factors = 2;
    provide_palindrome = 9999;
    test_arr = getGreatestMultiplePair(provide_palindrome, max_ten_power, \
        max_num_of_factors);
    running_product = 1;
    for (indx=0; indx<max_num_of_factors; indx++){
        running_product *= test_arr[indx];
        printf("\n%d -- %lu",test_arr[indx], running_product);
    }
    if (running_product != provide_palindrome)
        condition = false;

    /// trivial cases:
    // 3) 902 x 909 = 819918
    max_ten_power = 2;
    max_num_of_factors = 2;
    provide_palindrome = 819918;
    test_arr = getGreatestMultiplePair(provide_palindrome, max_ten_power, \
        max_num_of_factors);
    running_product = 1;
    for (indx=0; indx<max_num_of_factors; indx++){
        running_product *= test_arr[indx];
        printf("\n%d -- %lu",test_arr[indx], running_product);
    }
    if (running_product != provide_palindrome)
        condition = false;


    /// trivial cases:
    // 4) 919 * 1001 = 919919
    max_ten_power = 2;
    max_num_of_factors = 2;
    provide_palindrome = 919919;
    test_arr = getGreatestMultiplePair(provide_palindrome, max_ten_power, \
        max_num_of_factors);
    running_product = 1;
    for (indx=0; indx<max_num_of_factors; indx++){
        running_product *= (uint64_t) test_arr[indx];
        printf("\n%d -- %lu",test_arr[indx], running_product);
    }
    if (running_product != provide_palindrome){
        condition = false;
    }

    runTest(condition, method_tested, test_case, &test_passed);

    testResult(test_name,test_passed);
}

