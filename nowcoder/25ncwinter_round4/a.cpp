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
    int n ;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i != j && a[j] <= a[i])
            {
                ++cnt;
            }
        }
        if (cnt * 100 >= 80 * (n - 1))
        {
            ans += a[i];
        }
    }
    cout << ans << endl;
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