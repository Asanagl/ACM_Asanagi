#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << "start" << endl;
  string exe = "C:/Users/Asanagi/eropch-blog/.tmp/07/stress/main07.exe";
  string cmd = exe + " < case.in > main.out";
  cout << "cmd=" << cmd << endl;
  int rc = system(cmd.c_str());
  cout << "rc=" << rc << endl;
  ifstream f("main.out");
  string v; f >> v;
  cout << "out=" << v << endl;
  return 0;
}
