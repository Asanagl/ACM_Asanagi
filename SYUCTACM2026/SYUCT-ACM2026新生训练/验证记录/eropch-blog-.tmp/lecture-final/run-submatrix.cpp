#include <iostream>
using namespace std;

#define MAXN 1000

int a[MAXN][MAXN];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    if (n <= 0 || n > MAXN || m <= 0 || m > MAXN)
    {
        return 0;
    }

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> a[row][column];
        }
    }

    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;

        long long subSum = 0;
        for (int row = r1; row <= r2; row++)
        {
            for (int column = c1; column <= c2; column++)
            {
                subSum += a[row][column];
            }
        }

        cout << subSum << '\n';
    }
    return 0;
}
