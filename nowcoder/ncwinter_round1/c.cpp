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
    int n;
    cin >> n ;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n <= 2) {
        cout << accumulate(a.begin(), a.end(), 0LL) << endl;
        return ;
    }
    vector<ll> pref(n);
    pref[0] = LLONG_MIN;
    for (int i = 1; i < n; ++i) {
        pref[i] = max(pref[i-1], a[i-1]);
    }
    vector<ll> repref(n);
    repref[n-1] = LLONG_MIN;
    for (int i = n - 2; i >= 0; --i) {
        repref[i] = max(repref[i+1], a[i+1]);
    }
    
    ll ans = a[0] + a[n - 1];
    for (int i = 1; i < n - 1; ++i) {
        ans += max(pref[i], repref[i]); 
    }
    
    cout << ans << endl;
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            solve();
    }
    return 0;
}