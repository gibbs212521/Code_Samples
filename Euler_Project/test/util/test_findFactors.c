#include "test_findFactors.h"

void factors_test_suite()
{
    test_1_is_factor();
    test_2_find_all_factors();
    test_3_is_not_factor();
    test_4_eliminate_all_non_factors();
}

void test_1_is_factor(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "Is A Factor Test";

    /// CASE 1
//  char _t_guide_[30] = "                             "
    char test_case[30] = "Compare to Known Factors     ";
//  char _method_guide[30] = "                         ";
    char method_tested[30] = "isFactor function        ";
    condition = true;

    int factor_array[16] = {2, 4, 8, 16, 32, 64, 3, 9, 27, 5,\
        25, 11, 17, 37, 101, 1009};
    int target_array[16];
    uint64_t target_number = 30460681627200;
    uint64_t running_number = target_number;
    struct InvStackHandler factor_stack;
    initializeInvStack(&factor_stack);

    long factor_indx = 2;
    while (factor_indx <= running_number){
        while (isFactor(factor_indx, running_number)){
            factor_stack.push(&factor_stack, factor_indx);
            running_number = (uint64_t) (running_number / factor_indx);
        }
        factor_indx++;
    }
    int last_factor = 0, power_indx = 1;
    int current_factor;
    for (int solution_indx=0; solution_indx<16; solution_indx++){
        if (factor_stack.stack_depth == 0){
            condition = false;
            break;
        }
        current_factor = factor_stack.pop(&factor_stack);
        if (last_factor == current_factor){
            power_indx++;
            target_array[solution_indx] = powf(current_factor, power_indx); 
        }
        else{
            power_indx=1;
            target_array[solution_indx] = current_factor;
            last_factor = current_factor;
        }
    }
    if (factor_stack.stack_depth != 0)
        condition = false;

    for (int indx=0; indx<16; indx++){
        if (factor_array[indx] != target_array[indx])
            condition = false;
    }
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 2
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Validation of Factor Results ");
    strcpy(method_tested,"getLCMFactors           ");
    condition = true;

    struct StackHandler test_stack;
    initializeStack(&test_stack);

    buildFactorStack(&test_stack, target_number);
    int * test_array = getLCMFactors(&test_stack);
    int * test_target_array[16] = {2, 2, 2, 2, 2, 2, 3, 3, 3, 5, 5, 11, 17, 37,\
        101, 1009};
    // * new_factor_array = getFactorArray(&test_stack, &new_factor_array);

    if (test_stack.stack_depth == 0)
        condition = false;
    short depth = test_stack.stack_depth;
    for (int indx=0; indx<depth; indx++){
        if (test_array[indx] != test_target_array[depth-1-indx])
            condition = false;
    }

    runTest(condition, method_tested, test_case, &test_passed);
    while (test_stack.stack_depth)
        test_stack.pop(&test_stack);
    free(&test_stack);


    /// CASE 3
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Validation of Factor Results ");
    strcpy(method_tested,"getFactorArray           ");
    condition = true;

    struct StackHandler new_factor_stack;
    initializeStack(&new_factor_stack);

    buildFactorStack(&new_factor_stack, target_number);
    int * new_factor_array = getFactorArray(&new_factor_stack);

    if (new_factor_stack.stack_depth == 0)
        condition = false;
    depth = new_factor_stack.stack_depth;
    for (int indx=0; indx<depth; indx++){
        if (new_factor_array[indx] != target_array[depth-1-indx])
            condition = false;
    }

    runTest(condition, method_tested, test_case, &test_passed);
    while (new_factor_stack.stack_depth)
        new_factor_stack.pop(&new_factor_stack);
    free(&new_factor_stack);


    testResult(test_name, test_passed);
    while (factor_stack.stack_depth)
        factor_stack.pop(&factor_stack);
    free(&factor_stack);
}

void test_2_find_all_factors(){

}

void test_3_is_not_factor(){

}

void test_4_eliminate_all_non_factors(){

}
