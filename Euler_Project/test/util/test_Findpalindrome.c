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
    runTest(condition, method_tested, test_case, &test_passed);


    /// Case 4
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Test Combinations            ");
    strcpy(method_tested,"comboProdBuild function  ");
    condition = true;

    // trivial case
    int combo_5_5[15]= {25,20,15,10,5,16,12,8,4,9,6,3,4,2,1};
    int test_combo_5_5[15];

    comboProdBuild(5, &test_combo_5_5,15);
    for (int i=0; i < 15; i++)
    {
        if (combo_5_5[i] != test_combo_5_5[i])
            condition = false;
    }
    runTest(condition, method_tested, test_case, &test_passed);

//     /// Case 5
// //  strcpy(_t_guide_,"                             ");
//     strcpy(test_case,"Final Test                   ");
//     strcpy(method_tested,"findMaxPalindrome funct  ");
//     condition = true;

//     int max_var = 999;
//     int arr_depth = 100000;
//     int * palindrome_array[100000];
//     int test_is_palindrome = 0;
//     int test_indx = 0;
//     int max_palindrome_tested = 0;

//     comboProdBuild(max_var, &palindrome_array,arr_depth);

//     while (test_is_palindrome == 0)
//     {
//         if (test_indx == arr_depth)
//             break;
//         if (isPalindrome(palindrome_array[test_indx]))
//         {
//             if (palindrome_array[test_indx] > max_palindrome_tested)
//                 max_palindrome_tested = palindrome_array[test_indx];
//         }
//         test_indx++;
//     }

//     printf("\n\n%d\n%d\n\n",max_palindrome_tested,test_indx);

//     runTest(condition, method_tested, test_case, &test_passed);

    testResult(test_name,test_passed);
}

