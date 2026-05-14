#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    int n;
    int total = 0;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    for (int j = 0; j < n; j++)
    {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            int val = mat[i][j];

            int di = j * n + 1;
            int gao = j * n + n;

            if (val >= di&& val <= gao)
            {
                int k = val - j * n;
                int s = (k - 1 - i + n) % n;
                count[s]++;
            }
        }
        int ttstep = INF;
        for (int s = 0; s < n; s++)
        {
            int cost = s + (n - count[s]);
            if (cost < ttstep) {
                ttstep = cost;
            }
        }
        total += ttstep;
    }
    cout << total << endl;
}

signed main()
{
    IOS;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}