#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int a = 1; a <= n; a++)
    {
        for (int b = a + 1; b <= n; b++)
        {
            cout << a << ' ' << b << '\n';
        }
    }
    return 0;
}
