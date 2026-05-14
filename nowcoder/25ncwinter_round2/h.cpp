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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    vector<int> v(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (mp.find(a[i]) != mp.end())
        {
            v[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }
    int cnts = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int t;
        if (v[i] == -1)
        {
            t = i + 1;
        }
        else
        {
            t = i - v[i];
        }
        cnts += t;
        ans += cnts * (n - i);
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