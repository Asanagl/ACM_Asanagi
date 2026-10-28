#include <bits/stdc++.h>
using namespace std;
int main(){
  cerr<<"a\n";
  string cmd = string("C:/Users/Asanagi/eropch-blog/.tmp/07/stress/main07.exe") + " < case.in > main.out";
  cerr<<"cmd="<<cmd<<"\n";
  int rc = system(cmd.c_str());
  cerr<<"rc="<<rc<<"\n";
  return 0;
}
