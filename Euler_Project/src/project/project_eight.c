#include "project_eight.h"

int project_8(){

    printf("\nProject 8 ran ");

    project_eight_test();

    return 0;
}

int project_eight_test(){

    setTestMaxArray(0);
    setTestRunningArray(0);
    printTestMaxArray();

    int test_skip_counter = 0, test_max_flag = 1, vector_length = 4;
    
    for (int char_vector_indx = 4; char_vector_indx < 18;char_vector_indx++)//1001; char_vector_indx++)
    {
        short short_input = short_input_array[char_vector_indx];
        if (short_input == '0')
            test_skip_counter = vector_length;
        if (test_skip_counter > 0){
            test_skip_counter--;
            if (test_skip_counter == 0)
                setTestRunningArray(char_vector_indx-vector_length+1);
        } else {
            printf("\ntest %d: %c", char_vector_indx, short_input);
            shiftTestRunningArray(short_input);
            printf("\n");
            printTestRunningArray();
        }
    }
    //// TOOD: /*
/*
        RETURN TO THIS AND WORK ON ALGORITHM THAT AVOIDS MULITPLICATION

        Example:
        int max_vector_array = [0,0,0,0]
        for i in 4{
            if (running_element == max_array[i])
                max_vector_array[i]--;
        }

        ISSUE HANDLING RECURRNET NUMBERS SUCH AS 3 INSTANCES OF NINE 
        as in 4 element product example
*/
    
    return 0;
}

void setTestMaxArray(int initial_vector){
    for (int i = 0; i < 4; i++)
        test_8_array[i] = short_input_array[i + initial_vector];
}
void setTestRunningArray(int initial_vector){
    for (int i = 0; i < 4; i++)
        test_8_running_array[i] = short_input_array[i + initial_vector];
}
void shiftTestRunningArray(char input){
    test_8_running_array[0] = test_8_running_array[1];
    test_8_running_array[1] = test_8_running_array[2];
    test_8_running_array[2] = test_8_running_array[3];
    test_8_running_array[3] = input;
}


void printTestMaxArray(){
    printf("%c%c%c%c", test_8_array[0], test_8_array[1], test_8_array[2],\
        test_8_array[3]);
};
void printTestRunningArray(){
    printf("%c%c%c%c", test_8_running_array[0], test_8_running_array[1],\
        test_8_running_array[2], test_8_running_array[3]);
};