#ifndef __EULER_PROJECT_BASE_H__
#define __EULER_PROJECT_BASE_H__
#define MIN_INT_VAL -2147483648
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct Stack
{
    int data;
    struct Stack * next_ptr;
};

typedef struct Stack *stack_ptr;

struct StackHandler
{
    /// Class Variables
    // int top_value;   // Top Stack Vector Data w/out popping stack
        //// TODO: top_value should not be callable; utilize a getter method
        //          in order to compensate for NULL Vector
    int bottom;
    int stack_depth;
    short _shift_state;  // DEV PLACEHOLDEER 

    /// Class Pointers
    struct Stack * FILO_stack;
    struct Stack * bottom_ptr;
    
    /// Class Method Vectors
    int (*getTopValue)(struct StackHandler * this);
    int (*pop)(struct StackHandler * this);
    void (*shift)(struct StackHandler * this);
    void (*unshift)(struct StackHandler * this);  
    void (*push)(struct StackHandler * this,
                    int value);
};


void buildFILOStack(struct Stack * this);
void initializeStack(struct StackHandler * this);

int __get_top_stack_value__(struct StackHandler * this);
void __FILO_stack_push__(struct StackHandler * this, int value);
int __FILO_stack_pop__(struct StackHandler * this);
void __FILO_stack_shift__(struct StackHandler * this, bool is_to_shift_up);

void __FILO_stack_shift_up__(struct StackHandler * this);
void __FILO_stack_shift_down__(struct StackHandler * this);



struct InvStackHandler
{
    /// Class Variables
    // int top_value;   // Top Stack Vector Data w/out popping stack
        //// TODO: top_value should not be callable; utilize a getter method
        //          in order to compensate for NULL Vector
    int top;
    int stack_depth;
    short _shift_state;  // DEV PLACEHOLDEER --> delete once testing is complete

    /// Class Pointers
    // struct Stack * FILO_stack;
    struct Stack * FIFO_stack;
    struct Stack * top_ptr;
    
    /// Class Method Vectors
    int (*getBottomValue)(struct InvStackHandler * this);
    int (*pop)(struct InvStackHandler * this);
    void (*shift)(struct InvStackHandler * this);
    void (*unshift)(struct InvStackHandler * this);  
    void (*push)(struct InvStackHandler * this,
                    int value);
};


void buildFIFOStack(struct Stack * this);
void initializeInvStack(struct InvStackHandler * this);

int __get_bottom_stack_value__(struct InvStackHandler * this);
void __FIFO_stack_push__(struct InvStackHandler * this, int value);
int __FIFO_stack_pop__(struct InvStackHandler * this);
void __FIFO_stack_shift__(struct InvStackHandler * this, bool is_to_shift_down);

void __FIFO_stack_shift_down__(struct InvStackHandler * this);
void __FIFO_stack_shift_up__(struct InvStackHandler * this);


#endif