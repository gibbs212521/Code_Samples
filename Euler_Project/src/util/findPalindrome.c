#include "findPalindrome.h"

long long nextPalindrome(long long current_palindrome){
    /// This function is limited to XXXXXX 3 pair palindromes
    
    int inner_pair, parital_pair, outter_pair;
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
        most_significant_value_stack.pop(&least_significant_value_stack);
    // free(&least_significant_value_stack);
    ///     END OF GARBAGE COLLECTION ///

    return is_palindrome;
}

//// TODO: REAPPROACH FROM DRAWING BOARD ////
/// initial build out has issues with exceeding factor dot-product limit 
/// prematurely.
/// Attempted patch is too complicated and not abstract enough.
////  PLEASE ANALYZE BEFORE REWRITING  /////

int * getGreatestMultiplePair(uint64_t palindrome, int max_factor_ten_power, \
        int num_of_factors){
    /// Build return array
    int array_depth = num_of_factors;
    int * arr = (int *) malloc(sizeof(int) * array_depth);
    int * arr_length = (int *) malloc(sizeof(int) * array_depth);
    /// Define factors
    int maximum_factor_size = pow(10,(max_factor_ten_power+1));
    stack_handle factorStack;
    initializeStack(&factorStack);
    buildFactorStack(&factorStack, palindrome);
    int factor_arr_depth = factorStack.stack_depth;
    int * factor_array = getLCMFactors(&factorStack);

    /// Fill return array
    arr_length[0]=0;
    int running_factor_product = 1;
    int next_factor_product = 1;
    int factor_product_indx = 0;
    int _overflow_flag_ = 0;
    int indx;
    for (indx=0; indx < factor_arr_depth; indx++)
    {
        next_factor_product *= factor_array[indx];
        if (next_factor_product >= maximum_factor_size){
            if (factor_product_indx == (array_depth-1)){
                /// overflow protocol
                arr[factor_product_indx] = next_factor_product;
                printf("\n--------\t %d input into %drd arrray", running_factor_product,\
                 factor_product_indx);
                _overflow_flag_ = 1;
            } else {
                printf("\n--------\t %d input into %drd arrray", running_factor_product,\
                 factor_product_indx);
                printf("\n%d is max factor size", maximum_factor_size);
                arr[factor_product_indx] = running_factor_product;
                factor_product_indx++;
                next_factor_product = factor_array[indx];
                arr_length[factor_product_indx]=0;
        }}
        running_factor_product = next_factor_product;
        arr_length[factor_product_indx]++;
    }
    if (running_factor_product > maximum_factor_size)
                    _overflow_flag_ = 1;
    // printf("\n|-------\t %d input into %drd arrray", running_factor_product, factor_product_indx);
    // arr[factor_product_indx] = running_factor_product;
    

    /// balancing arrays
    int array_A_len = arr_length[0] - 1;
    int array_B_len = arr_length[1] - 1;
    int rerun_limit = 10;
    int rerun_indx = 0;
    int sub_indx = 0;
    int factor_indx = 0;
    stack_handle factorStack_A, factorStack_B;
    int * factors_A, * factors_B;
    int swapping_A, swapping_B;

    printf("\n\n%d,\n\n",_overflow_flag_);
    while((rerun_indx < rerun_limit) && _overflow_flag_)
    {
        buildFactorStack(&factorStack_A, arr[0]);
        buildFactorStack(&factorStack_B, arr[1]);
        factors_A = getLCMFactors(&factorStack_A);
        factors_B = getLCMFactors(&factorStack_B);
        if (rerun_indx == 0){
            swapping_A = factors_A[array_A_len];
            swapping_B = factors_B[array_B_len];
            factors_A[array_A_len] = swapping_B;
            factors_B[array_B_len] = swapping_A;
            if ((dotProductFactorArray(factors_A, array_A_len) > maximum_factor_size) \
                || (dotProductFactorArray(factors_B, array_B_len) > maximum_factor_size))
                _overflow_flag_ = 1;
            else {
                _overflow_flag_ = 0;
                arr[0] = dotProductFactorArray(factors_A, array_A_len);
                arr[1] = dotProductFactorArray(factors_B, array_B_len);
            }
        }
        rerun_indx++;
    }
    

    return arr;

}

