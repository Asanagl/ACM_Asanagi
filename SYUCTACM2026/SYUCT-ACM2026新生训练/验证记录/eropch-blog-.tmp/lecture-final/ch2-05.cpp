#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a != 0 && b % a == 0)
    {
        cout << "divisible\n";
    }
    else
    {
        cout << "not divisible\n";
    }
    return 0;
}
