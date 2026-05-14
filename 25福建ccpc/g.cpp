#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
using ld = long double ;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll k;
    cin >> k;
    vector<ll> pre (n, 0);
    for (int i = 1; i < n; i++) {
        ll diff = max ( 0LL, a[i] - a[i-1] ) ;
        pre[i] = pre[i-1] + diff;
    }
    while (m--) 
    {
        int s, t;
        cin >> s >> t;
        ll sum = pre[t-1] - pre[s-1];
        cout << k + sum << endl;
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

