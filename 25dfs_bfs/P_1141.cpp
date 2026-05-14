#include <bits/stdc++.h>
using namespace std;
int n, m, b[1005][1005], c[1000005], cnt, sum;
char a[1005][1005];
bool pd[1005][1005];
int fx[5] = {0, 1, 0, -1, 0};
int fy[5] = {0, 0, 1, 0, -1};
void dfs(int i, int j, int k)
{
    b[i][j] = k;
    sum++;
    for (int nmsl = 1; nmsl <= 4; nmsl++)
    {
        int x = i + fx[nmsl], y = j + fy[nmsl];
        if ((!(!x || !y || x > n || y > n || b[x][y])) && a[x][y] != a[i][j])
        {
            dfs(x, y, k);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (b[i][j] == 0)
            {
                cnt++;
                sum = 0;
                dfs(i, j, cnt);
                c[cnt] = sum;
            }
        }
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << c[b[x][y]] << endl;
    }
}
