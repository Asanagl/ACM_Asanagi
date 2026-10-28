#include "testlib.h"
#include <cstdio>
int main(){
    fprintf(stderr,"start\n");
    registerValidation();
    fprintf(stderr,"registered\n");
    return 0;
}
