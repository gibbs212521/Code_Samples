#include "project_four.h"


int project_4()
{
    int max_var = 999;
    int arr_depth = 100000;
    int * palindrome_array[100000]={};
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
    printf("\n \tProject 5 solution : \t232,792,560 (by hand)");

    long long squared_sum, sum_squared, sum=0;
    for (int i=1; i<=100; i++)
    {
        sum += i;
        squared_sum += i * i;
    }
    sum_squared = sum * sum;
    long long summed_difference = sum_squared - squared_sum;

    printf("\n \tProject 6 solution : \t%lld (impromptu)", summed_difference);

    unsigned long max_prime_count = 10010;
    unsigned long prime_list[10010] = {};
    setPrimeListUint(prime_list, max_prime_count);
    unsigned long last_prime = prime_list[10000];

    printf("\n \tProject 7 solution : \t%lu @ 10001 primes",last_prime);


    

    return max_palindrome_tested;
}
