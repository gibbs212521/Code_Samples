#ifdef _WIN32
#include "util\test_stack_set.h"
#include "util\test_findFactors.h"
#include "util\test_findPrime.h"
#include "util\test_findPalindrome.h"
#elif __linux__
#include "util/test_stack_set.h"
#include "util/test_findFactors.h"
#include "util/test_findPrime.h"
#include "util/test_findPalindrome.h"
#endif

int main(){
    stack_set_test_suite();
    factors_test_suite();
    prime_test_suite();
    palindrome_test_suite();

    return 0;
}