#include <iostream>
#include <string>
using namespace std;

#define MAXN 100

int main()
{
    int n, m;
    cin >> n >> m;

    string grid[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '*')
            {
                count++;
            }
        }
    }

    cout << count << '\n';
    return 0;
}
