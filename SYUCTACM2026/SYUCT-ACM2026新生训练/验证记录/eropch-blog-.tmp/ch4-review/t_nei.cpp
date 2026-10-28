#include <iostream>
using namespace std;

#define MAXN 100

int main()
{
    cout << flush; // harness-only: flush stdio before reading (local MinGW-mcf quirk)
    int n, m;
    cin >> n >> m;

    if (n <= 0 || n > MAXN || m <= 0 || m > MAXN)
    {
        return 0;
    }

    int a[MAXN][MAXN];
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> a[row][column];
        }
    }

    int targetRow, targetColumn;
    cin >> targetRow >> targetColumn;

    long long neighborSum = 0;
    if (targetRow - 1 >= 0)
    {
        neighborSum += a[targetRow - 1][targetColumn];
    }
    if (targetRow + 1 < n)
    {
        neighborSum += a[targetRow + 1][targetColumn];
    }
    if (targetColumn - 1 >= 0)
    {
        neighborSum += a[targetRow][targetColumn - 1];
    }
    if (targetColumn + 1 < m)
    {
        neighborSum += a[targetRow][targetColumn + 1];
    }

    int dRow[] = {-1, 1, 0, 0};
    int dColumn[] = {0, 0, -1, 1};
    long long neighborSum2 = 0;
    for (int direction = 0; direction < 4; direction++)
    {
        int nextRow = targetRow + dRow[direction];
        int nextColumn = targetColumn + dColumn[direction];
        if (nextRow >= 0 && nextRow < n && nextColumn >= 0 && nextColumn < m)
        {
            neighborSum2 += a[nextRow][nextColumn];
        }
    }
    if (neighborSum != neighborSum2)
    {
        cout << "direction-array mismatch!\n";
        return 1;
    }

    cout << neighborSum << '\n';
    return 0;
}
