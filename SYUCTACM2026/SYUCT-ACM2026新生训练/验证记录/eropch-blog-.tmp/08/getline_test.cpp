#include <bits/stdc++.h>
int main(){std::string s,t;std::getline(std::cin,s);std::getline(std::cin,t);
size_t p=s.find(t);std::cout<<(p==std::string::npos?-1:(long long)p)<<"\n";}
