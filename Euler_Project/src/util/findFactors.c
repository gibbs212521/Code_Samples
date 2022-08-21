#include "findFactors.h"

bool isFactor(long test_value, uint64_t target)
{
    bool condition = false;
    if (target % test_value == 0)
        condition = true;
    return condition;
}

void buildFactorStack(struct StackHandler * ptrStackFILO, uint64_t target)
{
    uint64_t running_number = target;
    long factor_indx = 2;
    while (factor_indx <= running_number){
        while (isFactor(factor_indx, running_number)){
            ptrStackFILO->push(ptrStackFILO, factor_indx);
            running_number = (uint64_t) (running_number / factor_indx);
        }
        factor_indx++;
    }
}

void buildFactorInvStack(struct InvStackHandler * ptrStackFIFO, uint64_t target)
{
    uint64_t running_number = target;
    long factor_indx = 2;
    while (factor_indx <= running_number){
        while (isFactor(factor_indx, running_number)){
            ptrStackFIFO->push(ptrStackFIFO, factor_indx);
            running_number = (uint64_t) (running_number / factor_indx);
        }
        factor_indx++;
    }
}

int * getLCMFactors(struct StackHandler * ptrStackFILO)
{
    int depth = ptrStackFILO->stack_depth;
    int * arr = (int *) malloc(sizeof(int) * depth);
    int indx = 0;
    // creating artifacts
    while (ptrStackFILO->stack_depth){
        arr[indx] = ptrStackFILO->pop(ptrStackFILO);
        indx++;
    }
    // erasing above artifacts
    for (int indx=depth-1; indx>=0; indx--){
        ptrStackFILO->push(ptrStackFILO, arr[indx]);
    }
    return arr;
}

int * getFactorArray(struct StackHandler * ptrStackFILO)
{
    int depth = ptrStackFILO->stack_depth;
    int * arr = getLCMFactors(ptrStackFILO);

    int last_factor=0, power_indx=1;
    int current_factor;
    for (int indx=depth-1; indx>=0; indx--){
        current_factor = arr[indx];
        if (last_factor == current_factor){
            power_indx++;
            arr[indx] = (int) powf(current_factor, power_indx); 
        }
        else{
            power_indx=1;
            arr[indx] = current_factor;
            last_factor = current_factor;
        }
    }
    return arr;
}
