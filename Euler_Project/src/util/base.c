#include "base.h"

uint64_t dotProductFactorArray(int * array_A, int array_length){
    uint64_t running_product = 1;
    for (int indx=0; indx < array_length; indx++){
        running_product *= array_A[indx];
        printf("\n%llu", running_product);
    }
    return running_product;
}

