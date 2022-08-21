#ifdef _WIN32
#include "util\test_stack_set.h"
#include "util\test_findFactors.h"
#include "util\test_findPrime.h"
#elif __linux__
#include "util/test_stack_set.h"
#include "util/test_findFactors.h"
#include "util/test_findPrime.h"
#endif

int main(){
    stack_set_test_suite();
    factors_test_suite();
    prime_test_suite();

    return 0;
}