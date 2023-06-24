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
    
    //printf("\n\nTESTED \t\t %ld", integer);
    double brute_integer = (double) integer;
    double int_squared_root = sqrt(brute_integer);
    // printf("\nTEST %lf", int_squared_root);
    // printf("\nTEST %ld", (long) int_squared_root);
    /// brute force check
    for (long j=7; j <= (long) int_squared_root*2; j++)
        for (long k=1; k <= (long) int_squared_root*2; k++)
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
        || integer == 11
        || integer == 13
        )
        return true;
    long test_int = integer % 10;
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

/*
IF PRIME GOES INTO OTHER NUMBER, NUMBER IS NOT PRIME
CYCLE THROUGH PRIOR PRIMES
*/

bool setPrimeListUint( unsigned long * prime_list, unsigned long array_length)
{
    /*
    Takes empty array and builds out all primes to n^th prime number
    */
    struct InvStackBinHandler prime_stack, aux_stack;
    _bin_initializeInvStack(&prime_stack);
    _bin_initializeInvStack(&aux_stack);
    unsigned long running_limit, running_number, bin_operandis;
    int prime_index = 0, running_index = 1;

    // TRIVIAL START
    prime_stack.push(&prime_stack, 0x02);
    prime_stack.push(&prime_stack, 0x03);
    prime_list[0] = 0x02;
    prime_list[1] = 0x03;
    prime_index = 1;
    running_number = 5; // starting running number

    do
    {
        running_limit = prime_list[prime_index] * 2 - 1;
        bin_operandis = running_number;
        running_index = 1;
        do
        {
            /// BRUTE FORCE
            while (bin_operandis >= prime_list[running_index])
            {
                bin_operandis -= prime_list[running_index];
            }
            if (bin_operandis)
            {
                running_index++;
                bin_operandis = running_number;
            }
            else
            {
                running_number += 2;
                bin_operandis = running_number;
                running_index = 1;
            }
       } while (running_index <= prime_index);
        prime_index++;
        prime_stack.push(&prime_stack, running_number);
        prime_list[prime_index] = running_number;
        if (running_number > running_limit)
            return 0x01;
        running_number += 2;
        running_limit = prime_list[prime_index] * 2 - 1;
        running_index = 1;
    } while (prime_stack.stack_depth < array_length);

    for (unsigned long i = 0; i < array_length; i++)
    {
        prime_list[i] = prime_stack.pop(&prime_stack);
    };
    return 0x00;
}


bool brute_force_prime_uint(unsigned long integer)
{

return 0x00;
}

bool isPrimeUint(unsigned long integer)
{

return 0x00;
}

