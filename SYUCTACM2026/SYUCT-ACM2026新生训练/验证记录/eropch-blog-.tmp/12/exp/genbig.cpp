#include <bits/stdc++.h>
using namespace std;
int main(int argc,char**argv){int n=atoi(argv[1]),m=n;mt19937 rng(7);
 printf("%d %d\n",n,m);
 for(int t=0;t<2;t++) for(int i=0;i<n;i++){for(int j=0;j<m;j++){printf(j?" %d":"%d",(int)(rng()%2000001)-1000000);}putchar('\n');}}
