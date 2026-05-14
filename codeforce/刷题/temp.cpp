#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void solve()
{
    int n ;
    cin >> n ;
    vector <int> height (n) ;
    for (auto &it : height)
        cin >> it;
    if (n <= 2)
    {
        cout << 0;
    }
    else
    {
        vector<int> prefix(n);
        vector<int> surf(n);
        int mx = 0;
        prefix[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + height[i];
        }
        mx = prefix[n - 1];
        surf[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            surf[i] = mx - prefix[i];
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            ans += max(0LL, min(prefix[i - 1], surf[i + 1]) - height[i]);
        }
        cout << ans;
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