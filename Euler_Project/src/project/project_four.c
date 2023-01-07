#include "project_three.h"

int getFactors(stack_handle * stack, int value)
{
    if (stack->FILO_stack != NULL)
    {
        printf("Stack Handler is not empty");
        return 1;
    }
    return 0;
}

int getMaxPrimeFactor(stack_handle * stack, int value)
{
    int max_prime = 0;
    if (stack->FILO_stack != NULL)
    {
        printf("Stack Handler is not empty");
        return 1;
    }
    int end = (int) sqrt(value-1);
    // for (int 2=start; i<end; i++)

    return max_prime;
}

int project_3(uint64_t target_number)
{
    uint64_t maximum_prime_factor;
    long max_prime = 0;
    struct StackHandler stack;
    initializeStack(&stack);
    buildFactorStack(&stack, target_number);
    int * arr = getLCMFactors(&stack);
    for (int indx=0; indx<stack.stack_depth; indx++){
        if (brute_force_prime(arr[indx])){
            maximum_prime_factor = arr[indx];
            break;
        }
    }

    printf("\n \tProject 3 solution : \t%lld", maximum_prime_factor);

    return max_prime;
}
