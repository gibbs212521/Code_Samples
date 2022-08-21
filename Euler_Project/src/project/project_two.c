#include "project_two.h"

int nextFibonacciNumber(int current_value, int previous_value)
{
    return (current_value + previous_value);
}

int sumFibonacciEvensInRange(int max_number)
{
    int fib_even_sum = 2;   /// includes first even fib number
    int fib_number = 0;
    int num_one = 1;
    int num_two = 2;
    int iterator = 0;
    while (fib_number < max_number)
    {
        iterator++;
        fib_number = nextFibonacciNumber(num_one, num_two);
        if (fib_number >= max_number)
            break;
        num_one = num_two;
        num_two = fib_number;
        if (iterator != 3)
            continue;
        fib_even_sum += fib_number;
        iterator = 0;
    }
    return fib_even_sum;
}

int project_2()
{
    if (project_two_test())
        printf("\nProject 2 FAILD TRIVIAL CASE\n");
    int even_fibonacci_sum = 0;
    even_fibonacci_sum = sumFibonacciEvensInRange(4000000);
    printf("\n \tProject two solution : \t%d",even_fibonacci_sum);

    return even_fibonacci_sum;
}

int project_two_test()
{
    int nth_fib = nextFibonacciNumber(3,5);
    if (nth_fib != 8){
        printf("\nFIB GOES TO %d but should be 8", nth_fib);
        return 1;
        }
    int fib_even_sum = sumFibonacciEvensInRange(90);
    if (fib_even_sum != 44){
        printf("\nEVEN SUM GOES TO %d but should be 44", fib_even_sum);
        return 1;
        }
    fib_even_sum = sumFibonacciEvensInRange(180);
    if (fib_even_sum != 188){
        printf("\nEVEN SUM GOES TO %d but should be 188", fib_even_sum);
        return 1;
        }
    return 0;
}
