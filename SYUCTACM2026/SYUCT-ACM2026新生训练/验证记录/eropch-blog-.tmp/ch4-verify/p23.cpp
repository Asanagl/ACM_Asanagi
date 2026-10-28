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

    int a[MAXN][MAXN];
    long long rowSum[MAXN] = {};
    long long columnSum[MAXN] = {};

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> a[row][column];
            rowSum[row] += a[row][column];
            columnSum[column] += a[row][column];
        }
    }

    cout << "row sums:";
    for (int row = 0; row < n; row++)
    {
        cout << ' ' << rowSum[row];
    }
    cout << '\n';

    cout << "column sums:";
    for (int column = 0; column < m; column++)
    {
        cout << ' ' << columnSum[column];
    }
    cout << '\n';
    return 0;
}
