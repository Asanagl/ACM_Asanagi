#include <iostream>
#include <string>
int main(){
  std::string s,t; std::cin>>s>>t;
  size_t p = s.find(t);
  std::cerr << "p=" << p << " npos=" << std::string::npos << "\n";
  std::cout << (long long)p << "\n";
  return 0;
}
