#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << "equal\n";
    }
    else if (a < b)
    {
        cout << a << " < " << b << '\n';
    }
    else
    {
        cout << a << " > " << b << '\n';
    }
    return 0;
}
