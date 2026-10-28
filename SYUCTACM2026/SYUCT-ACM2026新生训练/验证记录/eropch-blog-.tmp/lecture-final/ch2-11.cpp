#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;

    if (c >= '0' && c <= '9')
    {
        cout << "digit " << c - '0' << '\n';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        cout << "uppercase\n";
    }
    else if (c >= 'a' && c <= 'z')
    {
        cout << "lowercase\n";
    }
    else
    {
        cout << "other\n";
    }
    return 0;
}
