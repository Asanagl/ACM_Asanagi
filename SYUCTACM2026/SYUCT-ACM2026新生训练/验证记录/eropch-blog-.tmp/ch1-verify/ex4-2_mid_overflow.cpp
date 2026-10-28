#include <iostream>
using namespace std;

int main()
{
    int a = 100000, b = 100000;
    long long wrong = a * b;
    long long right = 1LL * a * b;
    cout << wrong << '\n';
    cout << right << '\n';
    return 0;
}
