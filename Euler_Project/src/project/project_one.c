#include "project_one.h"

#ifdef _WIN32
#include ".\..\util\stack_set.h"
#elif __linux__
#include "./../util/stack_set.h"
#endif

// If we list all the natural numbers below 10 that are multiples of 3 or 5, 
//  we get 3, 5, 6 and 9. The sum of these multiples is 23.
//  Find the sum of all the multiples of 3 or 5 below 1000.

int sumProductsInRange(int factor_one, int factor_two, int max_number)
{
    int running_sum = 0;
    --max_number; // prevents inclusion
    int factor_one_elements = max_number / factor_one;
    int factor_two_elements = max_number / factor_two;
    for (int i=1; i<=factor_one_elements; i++){
        running_sum += factor_one * i;
    }
    for (int i=1; i<=factor_two_elements; i++){
        if (i % factor_one != 0)
            running_sum += factor_two * i;
    }
    return running_sum;
}


int project_1(int factor_one, int factor_two, int max_number){
    if (project_one_test())
        printf("Factor test Failed");
    int proj_one_solution = sumProductsInRange(factor_one, factor_two, max_number);
    printf("\n \tProject one solution : \t%d ",proj_one_solution);
    return 0;
}

int project_one_test()
{
    if (sumProductsInRange(3,5,10) != 23)
    {
        printf("\nTRIVIAL CASE FAILED\n");
        return 1;
    }
    return 0;
}

/// Silly me solved wrong problem
int sumPrimeNumbersInRange(int start, int end)
{
    int running_sum = 0;
    for (int i=start; i<=end; i++)
        if (brute_force_prime(i))
            running_sum += i;
    return running_sum;
}
/*
    return proj_one_solution;

*/
