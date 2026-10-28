#include <iostream>
using namespace std;

#define MAXN 100

int main()
{
    int n, m;
    cin >> n >> m;

    int matrix[MAXN][MAXN];
    long long rowSum[MAXN] = {};

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> matrix[row][column];
            rowSum[row] += matrix[row][column];
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cout << matrix[row][column] << (column + 1 == m ? '\n' : ' ');
        }
    }

    for (int row = 0; row < n; row++)
    {
        cout << rowSum[row] << (row + 1 == n ? '\n' : ' ');
    }
    return 0;
}
