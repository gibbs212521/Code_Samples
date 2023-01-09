#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#ifdef _WIN32
#include ".\project\project_one.h"
#include ".\project\project_two.h"
#include ".\project\project_three.h"
#include ".\project\project_four.h"
#elif __linux__
#include "./project/project_one.h"
#include ".\project\project_two.h"
#include "./project/project_three.h"
#include "./project/project_four.h"
#endif


int main(){
    printf("Hellow World!");
    project_1(3,5,1000);
    project_2();
    project_3(600851475143);
    project_4(997799);

    return 0;
}