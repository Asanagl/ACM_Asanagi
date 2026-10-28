#include "testlib.h"
#include <cstdio>
int main(){ printf("hi\n"); fflush(stdout); int x = __testlib_stack_size_check_dummy; (void)x; return 0; }
