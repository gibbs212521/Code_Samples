#ifdef _WIN32
#include "project\test_stack_set.h"
#elif __linux__
#include "project/test_stack_set.h"
#endif

int main(){
    stack_set_test_suite();

    return 0;
}