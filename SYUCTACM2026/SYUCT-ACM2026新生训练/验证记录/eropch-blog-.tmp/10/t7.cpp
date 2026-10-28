#include <iostream>
#include <string>
#include <cstdio>
int main(){std::string s; std::cin>>s; printf("s=[%s] fail=%d\n", s.c_str(), (int)std::cin.fail()); return 0;}
