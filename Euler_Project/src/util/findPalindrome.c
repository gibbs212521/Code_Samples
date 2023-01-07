#include "findPalindrome.h"

bool isPalindrome(long long palindrome_candidate){
    if (palindrome_candidate < 10)
        return false;
    bool is_palindrome = true;
    long long palindrome_test = palindrome_candidate;
    int palindrome_test_index=0;
    int palindrome_test_int;
    stack_handle most_significant_value_stack;
    initializeStack(&most_significant_value_stack);
    inv_stack_handle least_significant_value_stack;
    initializeInvStack(&least_significant_value_stack);

    while (palindrome_test != 0)
    {
        palindrome_test_int = palindrome_test % 10;
        palindrome_test -= palindrome_test % 10;
        palindrome_test /= 10;
        most_significant_value_stack.push(&most_significant_value_stack, palindrome_test_int);
        least_significant_value_stack.push(&least_significant_value_stack, palindrome_test_int);
    }

    // int palindrome_candidate_is_odd = (int) palindrome_candidate % 2;

    int most_sig_value, least_sig_value;
    bool sig_values_are_equal = 1;

    while (most_significant_value_stack.stack_depth && sig_values_are_equal)
    {
        most_sig_value = most_significant_value_stack.pop(&most_significant_value_stack);        
        least_sig_value = least_significant_value_stack.pop(&least_significant_value_stack);
        if (least_sig_value != most_sig_value)
        {
            sig_values_are_equal = false;
        }
    }
    
    is_palindrome = sig_values_are_equal;

    /// GARBAGE COLLECTION
    while (most_significant_value_stack.stack_depth)
        most_significant_value_stack.pop(&most_significant_value_stack);
    // free(&most_significant_value_stack);
    while (least_significant_value_stack.stack_depth)
        most_significant_value_stack.pop(&least_significant_value_stack);
    // free(&least_significant_value_stack);
    ///     END OF GARBAGE COLLECTION ///

    return is_palindrome;
}
