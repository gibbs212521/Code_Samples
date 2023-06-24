#include "test_stack_set.h"

void stack_set_test_suite(){
    linked_list_test_suite();
}

void linked_list_test_suite()
{
    test_1_FILO_stack_evaluation();
    test_2_FIFO_stack_evaluation();
    test_3_general_stack_evaluation();
    test_4_binary_FILO_stack_evaluation();
    test_5_binary_FIFO_stack_evaluation();
}

/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::                   ::::::::::::::::::::
:::::::::::::::::::: LINKED LIST STACK ::::::::::::::::::::
::::::::::::::::::::     TEST SUITE    ::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/
     
void test_1_FILO_stack_evaluation(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "FILO Stack Test";
    struct StackHandler stack;
    initializeStack(&stack);

    /// CASE 1
//  char _t_guide_[30] = "                             "
    char test_case[30] = "Basic Initialization Case    ";
//  char _method_guide[30] = "                         ";
    char method_tested[30] = "Stack.initialize         ";
    if (stack.FILO_stack == NULL){
    condition = true;
    } else {
    condition = false;
    }
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 2
    /// A Generalized Stack should push to top (1) and to bottom (0)
    stack.push(&stack,5);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Push to Top            ");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Stack.push               ");
    condition = (stack.getTopValue(&stack) == 5);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 3
    long top_value = stack.pop(&stack);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Pop-Top returns Top    ");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Stack.pop                ");
    condition = (top_value == 5);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 4
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"After Stack Pop-Top goes Null");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Stack.pop                ");
    condition = ((top_value == 5) && (stack.getTopValue(&stack) == MIN_INT_VAL)
        && (stack.FILO_stack == NULL));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 5
    short depth_goal = 13;
    for (long long i=1; i <= depth_goal; i++)
        stack.push(&stack, i);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Depth via Push         ");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Stack.push               ");
    condition = ((stack.getTopValue(&stack) == depth_goal)
        && (stack.stack_depth == depth_goal));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 6
    short depth_start = depth_goal;
    depth_goal = 5;
    for (long long i=depth_start-1; i >= depth_goal; i--)
        stack.pop(&stack);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Depth via Push & Pop   ");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Stack.pop                ");
    condition = ((stack.getTopValue(&stack) == depth_goal)
        && (stack.stack_depth == depth_goal));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 7
    depth_start = depth_goal;
    for (int i=depth_start-1; i >= 0; i--)
        stack.pop(&stack);
    top_value = stack.pop(&stack);
//  strcpy(_t_guide_,"        \     \                ");
    strcpy(test_case,"Popping \"NULL\" Without Stack ");
    strcpy(method_tested,"Stack.pop                ");
    condition = ((stack.getTopValue(&stack) == MIN_INT_VAL)
        && (top_value == MIN_INT_VAL));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 8
    depth_goal = 5;
    for (int i=1; i <= depth_goal; i++)
        stack.push(&stack,i);
    stack.shift(&stack);
    condition = true;
    for (int i=depth_goal-1; i >= 0; i--)
    {
        top_value = stack.pop(&stack);
        if (i) // index ends at 0
        {
            condition = condition && (top_value == i);
        } else {
            condition = condition && (top_value == depth_goal);
        }
    }
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Shift & Collect Elements     ");
    strcpy(method_tested,"Stack.shift              ");
    condition = ((stack.getTopValue(&stack) == MIN_INT_VAL)
        && condition);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 9
    depth_goal = 5;
    for (int i=1; i <= depth_goal; i++)
        stack.push(&stack,i);
    stack.unshift(&stack);
    condition = true;
    for (int i=0; i < depth_goal; i++)
    {
        top_value = stack.pop(&stack);
        if (i) // index starts at 0
        {
            condition = condition && (top_value == depth_goal-i+1);
        } else {
            condition = condition && (top_value == 1);
        }
    }
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Shift & Collect Elements     ");
    strcpy(method_tested,"Stack.shift              ");
    condition = ((stack.getTopValue(&stack) == MIN_INT_VAL)
        && condition);
    runTest(condition, method_tested, test_case, &test_passed);
    // unshift 

    /// CASE 10
    // full cycle shift

    /// CASE 11
    // full cycle unshift

    /// CASE 12
    // 30 % shift 10 % unshift case == 70 % shift 50 % unshift

    /// CLOSING STATEMENTS
    testResult(test_name, test_passed);
    while (stack.stack_depth)
        stack.pop(&stack);
    // free(&stack);
}

void test_2_FIFO_stack_evaluation(){

    bool test_passed = true;
    char test_name[] = "FIFO Stack Test";
    bool condition;
    struct InvStackHandler stack;
    initializeInvStack(&stack);

    /// CASE 1
//  char _t_guide_[30] = "                             "
    char test_case[30] = "Basic Initialization Case    ";
    char method_tested[30] = "Stack.initialize         ";
    if (stack.FIFO_stack == NULL){
    condition = true;
    } else {
    condition = false;
    }
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 2
    stack.push(&stack,4);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Push to Bottom         ");
    strcpy(method_tested,"Stack.push               ");
    condition = (stack.getBottomValue(&stack) == 4);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 3
    long bottom_value = stack.pop(&stack);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Pop-Bottom returns Bot ");
    strcpy(method_tested,"Stack.pop                ");
    condition = (bottom_value == 4);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 4
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"After Stack Pop-Bot goes Bot ");
    strcpy(method_tested,"Stack.pop                ");
    condition = ((bottom_value == 4) && (stack.getBottomValue(&stack) == MIN_INT_VAL)
        && (stack.FIFO_stack == NULL));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 5
    short depth_goal = 13;
    for (int i=depth_goal; i > 0; i--)
        stack.push(&stack, i);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Depth via Push         ");
    strcpy(method_tested,"Stack.push               ");
    condition = ((stack.getBottomValue(&stack) == depth_goal)
        && (stack.stack_depth == depth_goal)
        && (stack.top_ptr->data == 1));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 6
    short depth_start = depth_goal;
    depth_goal = 5;
    for (int i=depth_start-1; i >= depth_goal; i--)
        stack.pop(&stack);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Depth via Push & Pop   ");
    strcpy(method_tested,"Stack.pop                ");
    condition = ((stack.getBottomValue(&stack) == depth_goal)
        && (stack.stack_depth == depth_goal));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 7
    depth_start = depth_goal;
    for (int i=depth_start-1; i >= 0; i--){
        stack.pop(&stack);
    }
    /// printf patch only required after implementing factors_test_suite()
    printf("  \r"); ///Unknown Memory array issue :. printf is slapstick patch
    bottom_value = stack.pop(&stack);
//  strcpy(_t_guide_,"        \     \                ");
    strcpy(test_case,"Popping \"NULL\" Without Stack ");
    strcpy(method_tested,"Stack.pop                ");
    condition = ((stack.getBottomValue(&stack) == MIN_INT_VAL)
        && (bottom_value == MIN_INT_VAL));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 8
    depth_goal = 5;
    for (int i=depth_goal; i > 0; i--)
        stack.push(&stack,i);
    stack.shift(&stack);
    condition = true;
    for (int i=depth_goal-1; i >= 0; i--)
    {
        bottom_value = stack.pop(&stack);
        if (i) // index ends at 0
        {
            condition = condition && (bottom_value == i);
        } else {
            condition = condition && (bottom_value == depth_goal);
        }
    }
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Shift & Collect Elements     ");
    strcpy(method_tested,"Stack.shift              ");
    condition = ((stack.getBottomValue(&stack) == MIN_INT_VAL)
        && condition);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 9
    depth_goal = 5;
    for (int i=depth_goal; i > 0; i--)
        stack.push(&stack,i);
    stack.unshift(&stack);
    condition = true;
    for (int i=0; i < depth_goal; i++)
    {
        bottom_value = stack.pop(&stack);
        if (i) // index starts at 0
            condition = condition && (bottom_value == depth_goal-i+1);
        else
            condition = condition && (bottom_value == 1);
    }
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Unshift & Collect Elements   ");
    strcpy(method_tested,"Stack.unshift            ");
    condition = ((stack.getBottomValue(&stack) == MIN_INT_VAL)
        && condition);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 10
    // full cycle shift

    /// CASE 11
    // full cycle unshift

    /// CASE 12
    // 30 % shift 10 % unshift case == 70 % shift 50 % unshift


    /// CLOSING STATEMENTS
    testResult(test_name, test_passed);
    while (stack.stack_depth)
        stack.pop(&stack);
    // free(&stack);
}

void test_3_general_stack_evaluation(){

    bool test_passed = true;
    char test_name[] = "Generalized Stack Test";
    bool condition;
    // struct InvStackHandler stack;
    // initializeStack(&stack);


    //     /// FOR CASES 5-9
    //         // build dataset w/ 8 elements (4 top and 4 bottom)
    //         // Note general stack.shift maintains size of top & bottom
    // int top_stack_length = 4;
    // int bottom_stack_length = 3;
    // int top_set[4] = {40,30,20,10};
    // int bottom_set[3] = {3,2,1};
    // if (top_stack_length == bottom_stack_length){
    //     printf("CASE 12 of test_stack_set.c requires top_stack_length != bottom_stack_length");
    // }

    // for (int i=0; i<top_stack_length; i++)
    //     stack.push(&stack,top_set[i],1);
    // for (int i=0; i<bottom_stack_length; i++)
    //     stack.push(&stack,bottom_set[i],0);



    // /// CASE 8
    // top_value = stack.getTopValue(&stack);
    // stack.shift(1); // shift up  :: left-shift <<
    // test_case[30] = "Stack Shift-Up";
    // strcpy(method_tested,[30] = "Stack.shift";
    // condition = ((top_value == top_set[top_stack_length]) 
    //     && (stack.getTopValue(&stack) == top_set[top_stack_length-1])
    //     && (stack.bottom == top_set[top_stack_length]));
    // runTest(condition, method_tested, test_case, &test_passed);

    // /// CASE 9
    // top_value = stack.getTopValue(&stack);
    // stack.unshift(1); // un-shift up  :: right-shift >>
    // test_case[30] = "Stack Un-Shift-Up";
    // strcpy(method_tested,[30] = "Stack.unshift";
    // condition = ((top_value == top_set[top_stack_length-1]) 
    //     && (stack.getTopValue(&stack) == top_set[top_stack_length])
    //     && (stack.bottom == bottom_set[bottom_stack_length]));
    // runTest(condition, method_tested, test_case, &test_passed);

    // /// CASE 10
    // bottom_value = stack.bottom;
    // stack.shift(0); // shift down  :: right-shift >>
    // test_case[30] = "Stack Shift-Up";
    // strcpy(method_tested,[30] = "Stack.shift";
    // condition = ((bottom_value == bottom_set[bottom_stack_length]) 
    //     && (stack.bottom == bottom_set[bottom_stack_length-1])
    //     && (bottom_value.top == bottom_set[bottom_stack_length]));
    // runTest(condition, method_tested, test_case, &test_passed);

    // /// CASE 11
    // bottom_value = stack.bottom;
    // stack.unshift(0); // un-shift down  :: left-shift <<
    // test_case[30] = "Stack Un-Shift-Up";
    // strcpy(method_tested,[30] = "Stack.unshift";
    // condition = ((bottom_value == bottom_set[bottom_stack_length-1]) 
    //     && (stack.bottom == bottom_set[bottom_stack_length])
    //     && (stack.getTopValue(&stack) == top_set[top_stack_length]));
    // runTest(condition, method_tested, test_case, &test_passed);

    // /// CASE 12
    // int number_of_pops;
    // if (top_stack_length > bottom_stack_length){
    //     number_of_pops = bottom_stack_length-1;
    //     stack.shift(1); // shift up  :: right-shift >>
    // } else {
    //     number_of_pops = top_stack_length-1;
    //     stack.shift(0); // shift down  :: left-shift <<
    // }
    // condition = true;
    // test_case[30] = "Stack Depth Unaltered By Shift";
    // strcpy(method_tested,[30] = "Stack.shift";
    // for (int i=0; i<number_of_pops; i++){
    //     stack.pop(1);
    //     stack.pop(0);
    //     if (top_stack_length > bottom_stack_length){
    //         condition = condition 
    //             && (stack.getTopValue(&stack) == top_set[top_stack_length-2-i])
    //             && (stack.bottom == bottom_set[bottom_stack_length-i]);
    //     } else {
    //         condition = condition 
    //             && (stack.getTopValue(&stack) == top_set[top_stack_length-i])
    //             && (stack.bottom == bottom_set[bottom_stack_length-2-i]);
    //     }
    // }
    // stack.pop(1);
    // stack.pop(0);
    // if (top_stack_length > bottom_stack_length){
    //     condition = condition 
    //         && (stack.getTopValue(&stack) == top_set[0])
    //         && (stack.bottom == NULL);
    // } else {
    //     condition = condition 
    //         && (stack.getTopValue(&stack) == NULL)
    //         && (stack.bottom == bottom_set[0]);
    // }
    // runTest(condition, method_tested, test_case, &test_passed);

    // /// Combination Case

    /// CLOSING STATEMENTS
    // testResult(test_name, test_passed);
}

void test_4_binary_FILO_stack_evaluation(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "FILO BinStack Test";
    struct StackBinHandler stack;
    _bin_initializeStack(&stack);

    /// CASE 1
//  char _t_guide_[30] = "                             "
    char test_case[30] = "Basic Bin Initialization Case";
//  char _method_guide[30] = "                         ";
    char method_tested[30] = "Bin Stack.initialize     ";
    if (stack.FILO_stack == NULL){
    condition = true;
    } else {
    condition = false;
    }
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 2
    /// A Generalized Stack should push to top (1) and to bottom (0)
    stack.push(&stack,0X05);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Stack Push to Top        ");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Bin Stack.push           ");
    condition = (stack.getTopValue(&stack) == 0X05);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 3
    unsigned long top_value = stack.pop(&stack);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Stack Pop-Top returns Top");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Bin Stack.pop            ");
    condition = (top_value == 0X05);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 4
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"After Stack Pop-Top goes Null");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Bin Stack.pop            ");
    condition = ((top_value == 0X05) && (stack.getTopValue(&stack) == 0)
        && (stack.FILO_stack == NULL));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 5
    short depth_goal = 13;
    for (unsigned long long i=1; i <= depth_goal; i++)
        stack.push(&stack, i);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Stack Depth via Push    ");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Bin Stack.push           ");
    condition = ((stack.getTopValue(&stack) == depth_goal)
        && (stack.stack_depth == depth_goal));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 6
    short depth_start = depth_goal;
    depth_goal = 5;
    for (long long i=depth_start-1; i >= depth_goal; i--)
        stack.pop(&stack);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Stack Depth Push & Pop   ");
//  strcpy(_method_guide,"                         ");
    strcpy(method_tested,"Bin Stack.pop            ");
    condition = ((stack.getTopValue(&stack) == depth_goal)
        && (stack.stack_depth == depth_goal));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 7
    depth_start = depth_goal;
    for (int i=depth_start-1; i >= 0; i--)
        stack.pop(&stack);
    top_value = stack.pop(&stack);
//  strcpy(_t_guide_,"        \     \                ");
    strcpy(test_case,"Bin Pop \"NULL\" Without Stack ");
    strcpy(method_tested,"Bin Stack.pop            ");
    condition = ((stack.getTopValue(&stack) == 0)
        && (top_value == 0));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 8
    depth_goal = 5;
    for (int i=1; i <= depth_goal; i++)
        stack.push(&stack,i);
    stack.shift(&stack);
    condition = true;
    for (int i=depth_goal-1; i >= 0; i--)
    {
        top_value = stack.pop(&stack);
        if (i) // index ends at 0
        {
            condition = condition && (top_value == i);
        } else {
            condition = condition && (top_value == depth_goal);
        }
    }
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Shift & Collect Elements ");
    strcpy(method_tested,"Bin Stack.shift          ");
    condition = ((stack.getTopValue(&stack) == 0x00)
        && condition);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 9
    depth_goal = 5;
    for (int i=1; i <= depth_goal; i++)
        stack.push(&stack,i);
    stack.unshift(&stack);
    condition = true;
    for (int i=0; i < depth_goal; i++)
    {
        top_value = stack.pop(&stack);
        if (i) // index starts at 0
        {
            condition = condition && (top_value == depth_goal-i+1);
        } else {
            condition = condition && (top_value == 1);
        }
    }
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Unshift & Collect Element");
    strcpy(method_tested,"Bin Stack.shift          ");
    condition = ((stack.getTopValue(&stack) == 0x00)
        && condition);
    runTest(condition, method_tested, test_case, &test_passed);
    // unshift 

    /// CASE 10
    // full cycle shift

    /// CASE 11
    // full cycle unshift

    /// CASE 12
    // 30 % shift 10 % unshift case == 70 % shift 50 % unshift

    /// CLOSING STATEMENTS
    testResult(test_name, test_passed);
    while (stack.stack_depth)
        stack.pop(&stack);
    // free(&stack);
}

void test_5_binary_FIFO_stack_evaluation(){

    bool test_passed = true;
    char test_name[] = "Bin FIFO BinStack Test";
    bool condition;
    struct InvStackBinHandler stack;
    _bin_initializeInvStack(&stack);

    /// CASE 1
//  char _t_guide_[30] = "                             "
    char test_case[30] = "Bin Basic Initialization Case";
    char method_tested[30] = "Bin Stack.initialize     ";
    if (stack.FIFO_stack == NULL){
    condition = true;
    } else {
    condition = false;
    }
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 2
    stack.push(&stack,0x04);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Stack Push to Bottom     ");
    strcpy(method_tested,"Bin Stack.push           ");
    condition = (stack.getBottomValue(&stack) == 0x04);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 3
    unsigned long bottom_value = stack.pop(&stack);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Stack Pop-Bottom rtrn Bot");
    strcpy(method_tested,"Bin Stack.pop            ");
    condition = (bottom_value == 0x04);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 4
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin After Stk PopBot goes Bot");
    strcpy(method_tested,"Bin Stack.pop            ");
    condition = ((bottom_value == 0x04) && (stack.getBottomValue(&stack) == 0)
        && (stack.FIFO_stack == NULL));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 5
    short depth_goal = 13;
    for (int i=depth_goal; i > 0; i--)
        stack.push(&stack, i);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Stack Depth via Push     ");
    strcpy(method_tested,"Bin Stack.push           ");
    condition = ((stack.getBottomValue(&stack) == depth_goal)
        && (stack.stack_depth == depth_goal)
        && (stack.top_ptr->data == 1));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 6
    short depth_start = depth_goal;
    depth_goal = 5;
    for (int i=depth_start-1; i >= depth_goal; i--)
        stack.pop(&stack);
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Depth via Push & Pop   ");
    strcpy(method_tested,"Stack.pop                ");
    condition = ((stack.getBottomValue(&stack) == depth_goal)
        && (stack.stack_depth == depth_goal));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 7
    depth_start = depth_goal;
    for (int i=depth_start-1; i >= 0; i--){
        stack.pop(&stack);
    }
    /// printf patch only required after implementing factors_test_suite()
    printf("  \r"); ///Unknown Memory array issue :. printf is slapstick patch
    bottom_value = stack.pop(&stack);
//  strcpy(_t_guide_,"        \     \                ");
    strcpy(test_case,"Bin Pop \"NULL\" Without Stck");
    strcpy(method_tested,"Bin Stack.pop            ");
    condition = ((stack.getBottomValue(&stack) == 0)
        && (bottom_value == 0));
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 8
    depth_goal = 5;
    for (int i=depth_goal; i > 0; i--)
        stack.push(&stack,i);
    stack.shift(&stack);
    condition = true;
    for (int i=depth_goal-1; i >= 0; i--)
    {
        bottom_value = stack.pop(&stack);
        if (i) // index ends at 0
        {
            condition = condition && (bottom_value == i);
        } else {
            condition = condition && (bottom_value == depth_goal);
        }
    }
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Shift & Collect Elements ");
    strcpy(method_tested,"Bin Stack.shift          ");
    condition = ((stack.getBottomValue(&stack) == 0)
        && condition);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 9
    depth_goal = 5;
    for (int i=depth_goal; i > 0; i--)
        stack.push(&stack,i);
    stack.unshift(&stack);
    condition = true;
    for (int i=0; i < depth_goal; i++)
    {
        bottom_value = stack.pop(&stack);
        if (i) // index starts at 0
            condition = condition && (bottom_value == depth_goal-i+1);
        else
            condition = condition && (bottom_value == 1);
    }
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Bin Unshift & Collect Elemnts");
    strcpy(method_tested,"Bin Stack.unshift        ");
    condition = ((stack.getBottomValue(&stack) == 0)
        && condition);
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 10
    // full cycle shift

    /// CASE 11
    // full cycle unshift

    /// CASE 12
    // 30 % shift 10 % unshift case == 70 % shift 50 % unshift


    /// CLOSING STATEMENTS
    testResult(test_name, test_passed);
    while (stack.stack_depth)
        stack.pop(&stack);
    // free(&stack);
}

