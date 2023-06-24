#include "findPalindrome.h"

long long nextPalindrome(long long current_palindrome){
    /// This function is limited to XXXXXX 3 pair palindromes
    
    long long inner_pair, parital_pair, outter_pair;
    long long next_palindrome = current_palindrome;
    outter_pair = next_palindrome % 10;
    next_palindrome = (next_palindrome - outter_pair)/10;
    parital_pair = next_palindrome % 10;
    next_palindrome = (next_palindrome - parital_pair)/10;
    inner_pair = next_palindrome % 10;

    if (inner_pair == 0){
        inner_pair = 9;
        if (parital_pair == 0){
            parital_pair = 9;
            if (outter_pair == 0)
                return -1;
            else 
                outter_pair--;
        } else {
        parital_pair--;
    }} else {
        inner_pair--;
    }

    next_palindrome = 100001 * outter_pair;
    next_palindrome += 10010 * parital_pair;
    next_palindrome +=  1100 * inner_pair;
    
    if (outter_pair == 0)
        return -1;

    return next_palindrome;
}

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
        least_significant_value_stack.pop(&least_significant_value_stack);
    // free(&least_significant_value_stack);
    ///     END OF GARBAGE COLLECTION ///

    return is_palindrome;
}

//// TODO: REAPPROACH FROM DRAWING BOARD ////
/// initial build out has issues with exceeding factor dot-product limit 
/// prematurely.
/// Attempted patch is too complicated and not abstract enough.
//
/// Plese attempt to functionalize the program.
////  PLEASE ANALYZE BEFORE REWRITING  /////

    /////   REVAMPED APPROACH
/*

Build combination set with X depth

*/
void comboProdBuild(int max_var, int * product_array, int array_depth){
    int array_counter = array_depth;
    int array_indx = 0;
    if (array_counter == 0)
        return;
    for (int i = max_var; i > 0 ; i--)
    {
        for (int j = i; j > 0; j--)
        {
            product_array[array_indx] = i * j;
            array_counter--;
            if (array_counter == 0)
                return;
            array_indx++;
        }
    }
    
}

