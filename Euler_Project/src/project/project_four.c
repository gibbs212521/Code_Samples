#include "project_four.h"


int project_4()
{
    int max_var = 999;
    int arr_depth = 100000;
    int * palindrome_array[100000];
    int test_is_palindrome = 0;
    int test_indx = 0;
    int max_palindrome_tested = 0;

    comboProdBuild(max_var, &palindrome_array,arr_depth);

    while (test_is_palindrome == 0)
    {
        if (test_indx == arr_depth)
            break;
        if (isPalindrome(palindrome_array[test_indx]))
        {
            if (palindrome_array[test_indx] > max_palindrome_tested)
                max_palindrome_tested = palindrome_array[test_indx];
        }
        test_indx++;
    }
    
    printf("\n \tProject 4 solution : \t%d", max_palindrome_tested);

    return max_palindrome_tested;
}
