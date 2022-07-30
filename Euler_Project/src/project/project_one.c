#include "project_one.h"

// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//  Find the sum of all the multiples of 3 or 5 below 1000.


int findNextPrimeNumber(int current_prime_number){
    return 0;
}

int setFactorPowerArray(int product_of_factors){
    int *factor_power_array;
    int current_prime_number = 2;
    int remaining_product = product_of_factors;
    while ((remaining_product != current_prime_number )
            &&(remaining_product<current_prime_number)){
        while (remaining_product%current_prime_number==0)
        {
            remaining_product /= current_prime_number;
        }
        
        remaining_product%current_prime_number;
        remaining_product /= current_prime_number;
    }
    return 0;
}

int project_1(){
    int FIR_Multiple_Sum=0;
    StackHandler factor_power_array_stack;
    

    return 0;
}