#include "findPrime.h"


bool setPrimeList(int * prime_list, int array_length, int start, int end)
{
    /// If list of primes is longer than array_length return false as an error.

    bool is_within_bounds = true;

    return is_within_bounds;
}


int findNextPrimeNumber(int current_prime_number){
    int next_prime_number = -1;
    bool not_prime = true;
    int increment = 1;
    // while (not_prime)
    // {
        
    // }

    return next_prime_number;
}

bool brute_force_prime(int integer)
{
    if (isPrime(integer))
        return true;
    double int_squared_root = sqrt(integer-1);
    /// brute force check
    for (int j=7; j <= (int) int_squared_root+1; j++)
        for (int k=1; k <= (int) int_squared_root+1; k++)
            {
                if (integer % (j*k) == 0)
                    return false;
            }
    return true;
}

bool isPrime(int integer)
{
    // Trivial Case
    bool condition = false;
    if (integer == 2
        || integer == 3
        || integer == 5
        || integer == 7
        || integer == 13
        )
        return true;
    int test_int = integer % 10;
    if (abs((test_int % 2)-1))
        return condition;
    if ((test_int % 5) == 0)
        return condition;
    
    // Build Digit Stack
    int log_10_power = 0;
    for (int i=0; pow(10,log_10_power)<integer; i++)
        log_10_power = i;
    stack_handle digit_stack;
    initializeStack(&digit_stack);
    int running_int = integer;

    // Collect Digits into Digit Stack
    for (int i=1; i<log_10_power; i++)
    {
        test_int = (running_int / (int) pow(10,i-1)) % (int) pow(10,i); 
        digit_stack.push(&digit_stack, test_int);
        running_int -= (test_int * (int) pow(10,i-1));
    }
    // Process Digits Values
    running_int = 0;
    for (int i=0; i < digit_stack.stack_depth; i++)
    {
        running_int += digit_stack.pop(&digit_stack);
    }
    if (running_int % 3 == 0)
        return condition;
    double int_squared_root = sqrt(integer-1);
    /// one more than perfect square theorem
    if ((((int) int_squared_root) - int_squared_root) == 0)  
        return true;
    condition = true;
    
    return condition;
}

