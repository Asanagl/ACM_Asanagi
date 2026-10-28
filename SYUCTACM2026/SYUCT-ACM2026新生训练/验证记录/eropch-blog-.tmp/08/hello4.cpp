#include <iostream>
#include <string>
int main(){
  std::string s,t;
  bool a = static_cast<bool>(std::cin >> s);
  bool b = static_cast<bool>(std::cin >> t);
  std::cerr << "a=" << a << " b=" << b << " s=" << s.size() << " t=" << t.size() << "\n";
  return 0;
}
