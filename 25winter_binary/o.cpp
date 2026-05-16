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

void Asanagi()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    ll mid = n / 2;  
    ll low = a[mid], high = a[mid] + k;
    ll ans = low;
    while (low <= high) {
        ll mid_val = low + (high - low) / 2;
        ll need = 0;
        for (ll i = mid; i < n; i++) 
        {
            if (a[i] < mid_val) 
            {
                need += mid_val - a[i];
                if (need > k) break; 
            }
        }
        if (need <= k) 
        {
            ans = mid_val;
            low = mid_val + 1;
        } else high = mid_val - 1;
    }
    cout << ans << endl;
}

signed main()
{
    IOS;
    int t = 1 ;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}