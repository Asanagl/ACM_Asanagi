#include <iostream>
using namespace std;

#define MAXN 1000

int a[MAXN][MAXN];

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
            cin >> a[row][column];
        }
    }

    int maximum = a[0][0];
    int answerRow = 0;
    int answerColumn = 0;
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            if (a[row][column] > maximum)
            {
                maximum = a[row][column];
                answerRow = row;
                answerColumn = column;
            }
        }
    }

    cout << maximum << ' ' << answerRow + 1 << ' ' << answerColumn + 1 << '\n';
    return 0;
}
