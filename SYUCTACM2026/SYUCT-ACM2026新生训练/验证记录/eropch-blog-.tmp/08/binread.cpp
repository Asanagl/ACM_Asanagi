#include <bits/stdc++.h>
int main(){
  std::ifstream f("crlf.in", std::ios::binary);
  std::string s,t; std::getline(f,s); std::getline(f,t);
  std::cout<<"s.size="<<s.size()<<" t.size="<<t.size()
           <<" t.back="<<(int)(unsigned char)t.back()<<"\n";
}
