#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int pos, len;
    cin >> pos >> len;

    cout << s.substr(pos, len) << '\n';
    return 0;
}
