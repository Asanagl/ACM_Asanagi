#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc,char*argv[]){
    registerGen(argc,argv,1);
    fprintf(stderr,"after registerGen argc=%d\n",argc);
    rnd.setSeed(atoll(argv[2]));
    fprintf(stderr,"after seed\n");
    printf("a\n");
    return 0;
}
