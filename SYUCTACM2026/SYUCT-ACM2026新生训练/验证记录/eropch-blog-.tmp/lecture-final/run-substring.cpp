#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int l, r;
    cin >> s >> l >> r;
cout << s.substr(l - 1, r - l + 1) << '\n';
    return 0;
}
