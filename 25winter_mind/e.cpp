#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    int a[105][105];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'R')
                a[i][j] = 1;
            else
                a[i][j] = 2;
        }
    int ans = 0;
    for (int i = 1; i < m; i++)
        if (a[n][i] == 2)
            ans++;
    for (int i = 1; i < n; i++)
        if (a[i][m] == 1)
            ans++;
    cout << ans << endl;
}

signed main()
{
    IOS;
    int t  ;
    // t = 1 ; 
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}