#ifndef __EULER_PROJECT_STACK_H__
#define __EULER_PROJECT_STACK_H__
#define MIN_INT_VAL -2147483648
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct Stack
{
    long data;
    struct Stack * next_ptr;
};

typedef struct Stack *stack_ptr;

struct StackHandler
{
    /// Class Variables
    // long top_value;   // Top Stack Vector Data w/out popping stack
        //// TODO: top_value should not be callable; utilize a getter method
        //          in order to compensate for NULL Vector
    long bottom;
    int stack_depth;
    short _shift_state;  // DEV PLACEHOLDEER 

    /// Class Pointers
    struct Stack * FILO_stack;
    struct Stack * bottom_ptr;
    
    /// Class Method Vectors
    long (*getTopValue)(struct StackHandler * this);
    long (*pop)(struct StackHandler * this);
    void (*shift)(struct StackHandler * this);
    void (*unshift)(struct StackHandler * this);  
    void (*push)(struct StackHandler * this, long value);
};
typedef struct StackHandler stack_handle;


void buildFILOStack(struct Stack * this);
void initializeStack(struct StackHandler * this);

long __get_top_stack_value__(struct StackHandler * this);
void __FILO_stack_push__(struct StackHandler * this, long value);
long __FILO_stack_pop__(struct StackHandler * this);
void __FILO_stack_shift__(struct StackHandler * this, bool is_to_shift_up);

void __FILO_stack_shift_up__(struct StackHandler * this);
void __FILO_stack_shift_down__(struct StackHandler * this);



struct InvStackHandler
{
    /// Class Variables
    // long top_value;   // Top Stack Vector Data w/out popping stack
        //// TODO: top_value should not be callable; utilize a getter method
        //          in order to compensate for NULL Vector
    long top;
    int stack_depth;
    short _shift_state;  // DEV PLACEHOLDEER --> delete once testing is complete

    /// Class Pointers
    // struct Stack * FILO_stack;
    struct Stack * FIFO_stack;
    struct Stack * top_ptr;
    
    /// Class Method Vectors
    long (*getBottomValue)(struct InvStackHandler * this);
    long (*pop)(struct InvStackHandler * this);
    void (*shift)(struct InvStackHandler * this);
    void (*unshift)(struct InvStackHandler * this);  
    void (*push)(struct InvStackHandler * this, long value);
};
typedef struct InvStackHandler inv_stack_handle;


void buildFIFOStack(struct Stack * this);
void initializeInvStack(struct InvStackHandler * this);

long __get_bottom_stack_value__(struct InvStackHandler * this);
void __FIFO_stack_push__(struct InvStackHandler * this, long value);
long __FIFO_stack_pop__(struct InvStackHandler * this);
void __FIFO_stack_shift__(struct InvStackHandler * this, bool is_to_shift_down);

void __FIFO_stack_shift_down__(struct InvStackHandler * this);
void __FIFO_stack_shift_up__(struct InvStackHandler * this);

// /********************************************************************/ //
// /**********************  BINARY SERIES    ***************************/ //
// /********************************************************************/ //

struct Stack_Bin
{
    unsigned long data;
    struct Stack_Bin * bin_next_ptr;
};
typedef struct Stack_Bin *bin_stack_ptr;


typedef struct Stack *stack_ptr;


struct StackBinHandler
{
    /// Class Variables
    // unsigned long top_value;   // Top Stack_Bin Vector Data w/out popping stack
        //// TODO: top_value should not be callable; utilize a getter method
        //          in order to compensate for NULL Vector
    unsigned long bottom;
    unsigned long stack_depth;
    short _shift_state;  // DEV PLACEHOLDEER 

    /// Class Pointers
    struct Stack_Bin * FILO_stack;
    struct Stack_Bin * bottom_ptr;
    
    /// Class Method Vectors
    unsigned long (*getTopValue)(struct StackBinHandler * this);
    unsigned long (*pop)(struct StackBinHandler * this);
    void (*shift)(struct StackBinHandler * this);
    void (*unshift)(struct StackBinHandler * this);  
    void (*push)(struct StackBinHandler * this, unsigned long value);
};
typedef struct StackBinHandler stackBin_handle;


void _bin_buildFILOStack(struct Stack_Bin * this);
void _bin_initializeStack(struct StackBinHandler * this);

unsigned long _bin___get_top_stack_value__(struct StackBinHandler * this);
void _bin___FILO_stack_push__(struct StackBinHandler * this, unsigned long value);
unsigned long _bin___FILO_stack_pop__(struct StackBinHandler * this);
void _bin___FILO_stack_shift__(struct StackBinHandler * this, bool is_to_shift_up);

void _bin___FILO_stack_shift_up__(struct StackBinHandler * this);
void _bin___FILO_stack_shift_down__(struct StackBinHandler * this);



struct InvStackBinHandler
{
    /// Class Variables
    // unsigned long top_value;   // Top Stack_Bin Vector Data w/out popping stack
        //// TODO: top_value should not be callable; utilize a getter method
        //          in order to compensate for NULL Vector
    unsigned long top;
    unsigned long stack_depth;
    short _shift_state;  // DEV PLACEHOLDEER --> delete once testing is complete

    /// Class Pointers
    // struct Stack_Bin * FILO_stack;
    struct Stack_Bin * FIFO_stack;
    struct Stack_Bin * top_ptr;
    
    /// Class Method Vectors
    unsigned long (*getBottomValue)(struct InvStackBinHandler * this);
    unsigned long (*pop)(struct InvStackBinHandler * this);
    void (*shift)(struct InvStackBinHandler * this);
    void (*unshift)(struct InvStackBinHandler * this);  
    void (*push)(struct InvStackBinHandler * this, unsigned long value);
};
typedef struct InvStackBinHandler _bin_inv_stack_handle;


void _bin_buildFIFOStack(struct Stack_Bin * this);
void _bin_initializeInvStack(struct InvStackBinHandler * this);

unsigned long _bin___get_bottom_stack_value__(struct InvStackBinHandler * this);
void _bin___FIFO_stack_push__(struct InvStackBinHandler * this, unsigned long value);
unsigned long _bin___FIFO_stack_pop__(struct InvStackBinHandler * this);
void _bin___FIFO_stack_shift__(struct InvStackBinHandler * this, bool is_to_shift_down);

void _bin___FIFO_stack_shift_down__(struct InvStackBinHandler * this);
void _bin___FIFO_stack_shift_up__(struct InvStackBinHandler * this);




#endif