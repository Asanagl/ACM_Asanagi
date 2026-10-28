#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
  fprintf(stderr,"argc=%d\n",argc);
  for(int i=0;i<argc;i++) fprintf(stderr,"argv[%d]=%s\n",i,argv[i]);
  long long rounds = atoll(argv[1]);
  fprintf(stderr,"rounds=%lld\n",rounds);
  return 0;
}
