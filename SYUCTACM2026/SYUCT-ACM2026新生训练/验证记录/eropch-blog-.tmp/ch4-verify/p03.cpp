#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string name;
    cin >> n;
    getline(cin, name);
    cout << n << ' ' << "[" << name << "]" << '\n';
    return 0;
}
