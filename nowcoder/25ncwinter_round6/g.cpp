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
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> x(n), y(m);
    for (auto &it : x) cin >> it ;
    for (auto &it : y) cin >> it;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 0; i < n; i++) {
        v[i + 1] = v[i] + x[i];
    }
    int pos = 0;
    auto it = upper_bound(v.begin(), v.end(), pos);
    if (it != v.end() && *it < pos + l) {
        cout << "YES" << endl;
        return ;
    }
    for (int i = 0; i < m; i++) {
        pos += y[i];
        it = upper_bound(v.begin(), v.end(), pos);
        if (it != v.end() && *it < pos + l) {
            cout << "YES" << endl;
            return ;
        }
    }
    cout << "NO" << endl;
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