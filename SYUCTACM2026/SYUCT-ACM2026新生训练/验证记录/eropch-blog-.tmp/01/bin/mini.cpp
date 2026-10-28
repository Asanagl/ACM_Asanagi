#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    if(!(cin >> s)) return 42;
    cout << s.size() << " X\n";
    return 0;
}
