#include <iostream>
using namespace std;

#define MAXN 100

int main()
{
    int n;
    cin >> n;

    if (n <= 0 || n > MAXN)
    {
        return 0;
    }

    int a[MAXN][MAXN];
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n; column++)
        {
            cin >> a[row][column];
        }
    }

    long long mainSum = 0;
    long long antiSum = 0;
    for (int row = 0; row < n; row++)
    {
        mainSum += a[row][row];
        antiSum += a[row][n - 1 - row];
    }

    cout << "main diagonal = " << mainSum << '\n';
    cout << "anti diagonal = " << antiSum << '\n';
    return 0;
}
