#include <iostream>
using namespace std;

#define MAXN 100

int main()
{
    int n, m;
    cin >> n >> m;

    if (n <= 0 || n > MAXN || m <= 0 || m > MAXN)
    {
        return 0;
    }

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            if ((row + column) % 2 == 0)
            {
                cout << 'B';
            }
            else
            {
                cout << 'W';
            }
        }
        cout << '\n';
    }
    return 0;
}
