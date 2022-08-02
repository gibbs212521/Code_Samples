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
    for (int 2=start; i<end; i++)

    return max_prime;
}

int project_3(int max_number)
{
    if (project_three_test())
        printf("\nProject 3 FAILD TRIVIAL CASE\n");
    int max_prime = 0;
    stack_handle stack;
    initializeStack(&stack);
    getPrimeFactors(&stack, 600851475143);

    printf("\n \tProject 3 solution is : \t%d", stack.pop(&stack));

    return max_prime;
}

int project_three_test()
{

}
