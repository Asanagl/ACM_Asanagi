#include <iostream>
#include <string>
int main(){std::string s; std::getline(std::cin,s); std::cout<<"line:["<<s<<"] fail="<<std::cin.fail()<<"\n"; return 0;}
