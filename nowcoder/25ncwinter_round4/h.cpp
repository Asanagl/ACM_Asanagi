#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> v(505, vector<int>(505, 0));
    vector<vector<int>> air1(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> air1[i][j];
        }
    }
    vector<pair<int, int>> airi____;
    for (int dx = -2; dx <= 2; ++dx)
    {
        for (int dy = -2; dy <= 2; ++dy)
        {
            if (abs(dx) + abs(dy) <= 2)
            {
                airi____.push_back({dx, dy});
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (auto &d : airi____)
            {
                int x = i + d.first;
                int y = j + d.second;
                if (x >= 1 && x <= n && y >= 1 && y <= m)
                {
                    v[x][y] += air1[i][j];
                }
            }
        }
    }

    int maxn = 0;
    int maxx = 1, maxy = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (v[i][j] > maxn)
            {
                maxn = v[i][j];
                maxx = i;
                maxy = j;
            }
        }
    }

    while (q--)
    {
        int a, b, z;
        cin >> a >> b >> z;
        for (auto &d : airi____)
        {
            int x = a + d.first;
            int y = b + d.second;
            if (x >= 1 && x <= n && y >= 1 && y <= m)
            {
                v[x][y] += z;
                if (v[x][y] > maxn)
                {
                    maxn = v[x][y];
                    maxx = x;
                    maxy = y;
                }
            }
        }
        cout << maxx << " " << maxy << endl;
    }
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}