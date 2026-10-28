#include <iostream>
#include <string>
using namespace std;

#define MAXN 500

string grid[MAXN];
int counts[MAXN][MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int row = 0; row < n; row++)
    {
        cin >> grid[row];
    }

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            int count = 0;
            if (row > 0)
            {
                count += grid[row - 1][column] - '0';
            }
            if (row + 1 < n)
            {
                count += grid[row + 1][column] - '0';
            }
            if (column > 0)
            {
                count += grid[row][column - 1] - '0';
            }
            if (column + 1 < m)
            {
                count += grid[row][column + 1] - '0';
            }
            counts[row][column] = count;
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cout << counts[row][column] << (column + 1 == m ? '\n' : ' ');
        }
    }
    return 0;
}
