#include <iostream>
#include <cstdio>
int main(){int c = std::cin.get(); printf("cin.get=%d fail=%d eof=%d\n", c, (int)std::cin.fail(), (int)std::cin.eof()); return 0;}
