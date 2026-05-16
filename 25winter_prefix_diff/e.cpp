#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 2001;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n;
    cin >> n;
    vector<vector<int>> pre(INF, vector<int>(INF, 0));
    for (int i = 0; i < n; i++) 
    {
        int x, y, w;
        cin >> x >> y >> w;
        pre[x][y] += w; 
    }
    
    for (int i = 0; i < INF; i++) 
    {
        for (int j = 0; j < INF; j++) {
            if (i > 0) pre[i][j] += pre[i-1][j];
            if (j > 0) pre[i][j] += pre[i][j-1];
            if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];
        }
    }
    int q;
    cin >> q;
    while (q--) 
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = pre[x2][y2];
        if (x1 > 0) ans -= pre[x1-1][y2];
        if (y1 > 0) ans -= pre[x2][y1-1];
        if (x1 > 0 && y1 > 0) ans += pre[x1-1][y1-1];
        cout << ans << endl;
    }
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}