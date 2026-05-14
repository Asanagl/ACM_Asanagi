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
    cin >> n;
    int m = 1 << n; // 何移位
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    long long total = 0;
    for (int j = 0; j < n; j++)
    {
        vector<int> b;
        vector<int> t;
        for (int i = 0; i < m; i++)
        {
            if ((a[i] >> j) & 1)
            {
                b.push_back(i);
            }
            if ((i >> j) & 1)
            {
                t.push_back(i);
            }
        }
        for (size_t k = 0; k < b.size(); k++)
        {
            total += abs(b[k] - t[k]);
        }
    }
    cout << total << endl ;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

