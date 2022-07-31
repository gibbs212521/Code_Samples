#include "base.h"



void initializeStack(struct StackHandler * this)
{
    this -> stack_depth = 0;   // Seems that assigning push adds 1 & pop subtracts 1
    this -> _shift_state = 0;
    this -> FILO_stack = NULL;
    this -> bottom_ptr = NULL;

    this -> getTopValue = __get_top_stack_value__;
    this -> push = __FILO_stack_push__;
    this -> pop = __FILO_stack_pop__;
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
}


/// StackHandler Methods ///

int __get_top_stack_value__(struct StackHandler * this)
{
    int top_value = MIN_INT_VAL; // maximum negative value
    if (this->FILO_stack != NULL)
        top_value = this->FILO_stack->data;

    return top_value;
}

int __get_bottom_stack_value__(struct InvStackHandler * this)
{
    int bottom_value = MIN_INT_VAL; // maximum negative value
    if (this->FIFO_stack != NULL)
        bottom_value = this->FIFO_stack->data;

    return bottom_value;
}




void __FILO_stack_push__(struct StackHandler * this, int value)
{
    stack_ptr pushed_ptr;

    pushed_ptr = malloc(sizeof(stack_ptr));

    if(pushed_ptr != NULL)
    {
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
}

int __FILO_stack_pop__(struct StackHandler * this)
{
    int popped_value;
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



void __FIFO_stack_push__(struct InvStackHandler * this, int value)
{
    stack_ptr pushed_ptr;

    pushed_ptr = malloc(sizeof(stack_ptr));

    if(pushed_ptr != NULL)
    {
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
}

int __FIFO_stack_pop__(struct InvStackHandler * this)
{
    int popped_value;

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
/*  |-------| --> PUSH(POP())-->|  TOP  |       POP(PUSH())     |-------|
    |  TOP  |                   |-------|       W/ FOR LOOP ^   |  MID  |
    |-------|   |\/\_/\/|  -->   PUSH(POP())    |-------|  |    |-------|
    |  MID  |   |  MID  |        W/ FOR LOOP ^  |  BOT  |  |__\ |  BOT  |
    |-------|   |-------|   |\/\_/\/|    |____\ |-------|     / |-------|
    |  BOT  |   |  BOT  |   |  BOT  |         / |  MID  |       |  TOP  |
    |-------|   |-------|   |-------|           |-------|       |-------|
*/
    int popped_value;
    stack_ptr popped_ptr;
    stack_ptr rolling_ptr;
    
    
    if(is_to_shift_up){
        if (this->bottom_ptr == NULL)
        {
            free(popped_ptr);
            return;
        }
        this->_shift_state += 1;

        popped_ptr = this->bottom_ptr;
        popped_value = (popped_ptr)->data;
        this->bottom_ptr = NULL;
        free(popped_ptr);


    } else {
        this->_shift_state -= 1;
    }
    
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
    // int top
    // int tmp_pop_val;
    // stack_ptr tmp_ptr;
    if(is_to_shift_down){
        this->_shift_state += 1;
    } else {
        this->_shift_state -= 1;
    }
}
void __FIFO_stack_shift_down__(struct InvStackHandler * this)
{
    __FIFO_stack_shift__(this, true);
}
void __FIFO_stack_shift_up__(struct InvStackHandler * this)
{
    __FIFO_stack_shift__(this, false);
}

