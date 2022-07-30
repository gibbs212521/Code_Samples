#ifdef _WIN32
#include "project\test_base.h"
#elif __linux__
#include "project/test_base.h"
#endif

int main(){
    base_test_suite();

    return 0;
}