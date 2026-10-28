#include "testlib.h"
#include <cstdio>
#include <cstdlib>
int main(int argc,char**argv){
    fprintf(stderr,"A\n");
    registerGen(argc,argv,1);
    fprintf(stderr,"B\n");
    rnd.setSeed(atoll(argv[2]));
    fprintf(stderr,"C value=%d\n", rnd.next(0,25));
    printf("a\n");
    return 0;
}
