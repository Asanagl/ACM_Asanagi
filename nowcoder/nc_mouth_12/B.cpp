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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    while (q--) 
    {
        int k, x;
        cin >> k >> x;
        int pos = upper_bound(a.begin(), a.end(), x - 1) - a.begin();
        if (pos >= k) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
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

