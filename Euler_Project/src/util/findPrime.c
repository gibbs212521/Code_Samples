#include "findPrime.h"


bool setPrimeList(int * prime_list, int array_length, long start, long end)
{
    /// start and end are set as uint_64
    /// If list of primes is longer than array_length return false as an error.

    bool is_within_bounds = true;

    return is_within_bounds;
}


long findNextPrimeNumber(long current_prime_number){
    long next_prime_number = -1;
    bool not_prime = true;
    int increment = 1;
    // while (not_prime)
    // {
        
    // }

    return next_prime_number;
}

bool brute_force_prime(long integer)
{
    if (isPrime(integer))
        return true;
    double int_squared_root = sqrt(integer-1);
    /// brute force check
    for (long j=7; j <= (long) int_squared_root+1; j++)
        for (long k=1; k <= (long) int_squared_root+1; k++)
            {
                if (integer % (j*k) == 0)
                    return false;
            }
    return true;
}

bool isPrime(long integer)
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
    short test_int = integer % 10;
    if (abs((test_int % 2)-1))
        return condition;
    if ((test_int % 5) == 0)
        return condition;
    
    // Build Digit Stack
    long log_10_power = 0;
    for (int i=0; pow(10,log_10_power)<integer; i++)
        log_10_power = i;
    stack_handle digit_stack;
    initializeStack(&digit_stack);
    long running_int = integer;

    // Collect Digits into Digit Stack
    for (int i=1; i<log_10_power; i++)
    {
        test_int = (running_int / (long) pow(10,i-1)) % (long) pow(10,i); 
        digit_stack.push(&digit_stack, test_int);
        running_int -= (test_int * (long) pow(10,i-1));
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
    if ((((long) int_squared_root) - int_squared_root) == 0)  
        return true;
    condition = true;
    
    return condition;
}

