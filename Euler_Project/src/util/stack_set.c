#include "stack_set.h"



void initializeStack(struct StackHandler * this)
{
    this -> stack_depth = 0;   // Seems that assigning push adds 1 & pop subtracts 1
    this -> _shift_state = 0;
    this -> FILO_stack = NULL;
    this -> bottom_ptr = NULL;

    this -> getTopValue = __get_top_stack_value__;
    this -> push = __FILO_stack_push__;
    this -> pop = __FILO_stack_pop__;
    this -> shift = __FILO_stack_shift_up__;
    this -> unshift = __FILO_stack_shift_down__;
}
void initializeInvStack(struct InvStackHandler * this)
{
    this -> stack_depth = 0;   // Seems that assigning push adds 1 & pop subtracts 1
    this -> _shift_state = 0;
    this -> FIFO_stack = NULL;
    this -> top_ptr = NULL;

    this -> getBottomValue = __get_bottom_stack_value__;
    this -> push = __FIFO_stack_push__;
    this -> pop = __FIFO_stack_pop__;
    this -> shift = __FIFO_stack_shift_down__;
    this -> unshift = __FIFO_stack_shift_up__;
}


/// StackHandler Methods ///

long __get_top_stack_value__(struct StackHandler * this)
{
    long top_value = MIN_INT_VAL; // maximum negative value
    if (this->FILO_stack != NULL)
        top_value = this->FILO_stack->data;

    return top_value;
}

long __get_bottom_stack_value__(struct InvStackHandler * this)
{
    long bottom_value = MIN_INT_VAL; // maximum negative value
    if (this->FIFO_stack != NULL)
        bottom_value = this->FIFO_stack->data;

    return bottom_value;
}




void __FILO_stack_push__(struct StackHandler * this, long value)
{
    stack_ptr pushed_ptr;

    pushed_ptr = malloc(sizeof(stack_ptr));

    if(pushed_ptr == NULL)
    {
        free(pushed_ptr);
        return;
    }

    pushed_ptr -> data = value;
    pushed_ptr -> next_ptr = this->FILO_stack;
    if (this -> FILO_stack == NULL)
    {
        this->bottom = value;
        this->bottom_ptr = pushed_ptr;
    } else {

    }
    this -> FILO_stack = pushed_ptr;
    this -> stack_depth++;

}

long __FILO_stack_pop__(struct StackHandler * this)
{
    long popped_value;
    stack_ptr popped_ptr;

    if (this->FILO_stack == NULL)
    {
        free(popped_ptr);
        return MIN_INT_VAL;
    }

    popped_ptr = this->FILO_stack;
    popped_value = (popped_ptr)->data;
    this->FILO_stack = (this->FILO_stack)->next_ptr;
    free(popped_ptr);
    this -> stack_depth--;

    return popped_value;
}



void __FIFO_stack_push__(struct InvStackHandler * this, long value)
{
    stack_ptr pushed_ptr;

    pushed_ptr = malloc(sizeof(stack_ptr));

    if (pushed_ptr == NULL)
    {
        free(pushed_ptr);
        return;
    }
    
    pushed_ptr -> data = value;
    pushed_ptr->next_ptr = NULL;

    if (this -> FIFO_stack == NULL)
    {
        this->FIFO_stack = pushed_ptr;
    } else {
        this->top_ptr->next_ptr = pushed_ptr;
    }
    this->top_ptr = pushed_ptr;
    this->top = value;
    this -> stack_depth++;

}

long __FIFO_stack_pop__(struct InvStackHandler * this)
{
    long popped_value;

    stack_ptr popped_ptr;

    if (this->FIFO_stack == NULL)
    {
        free(popped_ptr);
        return MIN_INT_VAL;
    }

    popped_ptr = this->FIFO_stack;
    popped_value = (popped_ptr)->data;
    this->FIFO_stack = (this->FIFO_stack)->next_ptr;
    free(popped_ptr);
    this -> stack_depth--;

    return popped_value;
}




void __FILO_stack_shift__(struct StackHandler * this, bool is_to_shift_up)
{
    /// APPROACH                |-------|
/*  |-------| --> PUSH(POP())-->|  TOP  |       PUSH(POP())     |-------|
    |  TOP  |                   |-------|       W/ FOR LOOP ^   |  MID  |
    |-------|   |\/\_/\/|  -->   PUSH(POP())    |-------|  |    |-------|
    |  MID  |   |  MID  |        W/ FOR LOOP ^  |  BOT  |  |__\ |  BOT  |
    |-------|   |-------|   |\/\_/\/|    |____\ |-------|     / |-------|
    |  BOT  |   |  BOT  |   |  BOT  |         / |  MID  |       |  TOP  |
    |-------|   |-------|   |-------|           |-------|       |-------|
       ^ &this->stack ^   &this->stack    temp_handle.stack    &this->stack
*/
    /// Argument
/*
    If constant shifting is required, consider utilizing a static/dynamic
    array where you shift do a rewrite of all elements with a paralell 
    read_clipped_end -> store_clipped_end -> Start Parallel Operation:
    read -> store -> verify -> write -> free(store) OPERAND-Function
        OR
    Parallel Operation: for (long n=1;n<len;n++) Copy(arr[n],arr[n-1])
    w/ serial operation.
    A stack shines when you need a simple and fast sequence using either
    FIFO or FILO sequences.
*/

    if (this->bottom_ptr == NULL)
        return; // If the stack is empty, cannot shift

    long popped_value;
    long temp_popped_value;

    stack_ptr popped_ptr;
    stack_ptr rolling_ptr;

    struct StackHandler *ptr_handle;

    ptr_handle = malloc(sizeof(struct  StackHandler));
    initializeStack(ptr_handle);

    if (ptr_handle == NULL)
    {
        free(ptr_handle);
        return;
    }

    if(is_to_shift_up){
        popped_value = this->pop(this);
        while (this->stack_depth)
            ptr_handle->push(ptr_handle, this->pop(this));
        this->push(this, popped_value);
        while (ptr_handle->stack_depth)
            this->push(this, ptr_handle->pop(ptr_handle));
    } else {
        while (this->stack_depth>1)
            ptr_handle->push(ptr_handle, this->pop(this));
        popped_value = this->pop(this);
        while (ptr_handle->stack_depth)
            this->push(this, ptr_handle->pop(ptr_handle));            
        this->push(this, popped_value);
    }

    free(ptr_handle);
}
void __FILO_stack_shift_up__(struct StackHandler * this)
{
    __FILO_stack_shift__(this, true);
    
}
void __FILO_stack_shift_down__(struct StackHandler * this)
{
    __FILO_stack_shift__(this, false);
    
}


void __FIFO_stack_shift__(struct InvStackHandler * this, bool is_to_shift_down)
{

    if (this->top_ptr == NULL)
        return; // If the stack is empty, cannot shift

    long popped_value;

    struct InvStackHandler *ptr_handle;

    ptr_handle = malloc(sizeof(struct  InvStackHandler));
    initializeInvStack(ptr_handle);

    if (ptr_handle == NULL)
    {
        free(ptr_handle);
        printf("__FIFO_stack_shift__ malloc failed");
        return;
    }

    if (is_to_shift_down == 0){
        while (this->stack_depth>1)
            ptr_handle->push(ptr_handle, this->pop(this));
        while (ptr_handle->stack_depth)
            this->push(this, ptr_handle->pop(ptr_handle));
    } else
        this->push(this,this->pop(this));

    free(ptr_handle);
}
void __FIFO_stack_shift_down__(struct InvStackHandler * this)
{
    __FIFO_stack_shift__(this, true);
}
void __FIFO_stack_shift_up__(struct InvStackHandler * this)
{
    __FIFO_stack_shift__(this, false);
}

