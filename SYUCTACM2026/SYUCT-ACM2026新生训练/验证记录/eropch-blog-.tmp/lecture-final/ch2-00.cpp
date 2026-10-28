#include <iostream>
using namespace std;

int main()
{
    int x = -7;
    int m = 3;
    int remainder = x % m;
    if (remainder < 0)
    {
        remainder += m;
    }

    cout << remainder << '\n';
    return 0;
}
