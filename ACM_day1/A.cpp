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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> premin(n), premax(n);
    premin[0] = a[0];
    premax[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        premin[i] = min(premin[i - 1], a[i]);
        premax[i] = max(premax[i - 1], a[i]);
    }

    vector<int> sufmin(n), sufmax(n);
    sufmin[n - 1] = a[n - 1];
    sufmax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sufmin[i] = min(sufmin[i + 1], a[i]);
        sufmax[i] = max(sufmax[i + 1], a[i]);
    }
    int ans = INF;
    for (int i = 1; i <= n - k - 1; i++)
    {
        int j = n - k - i;
        int amin = min(premin[i - 1], sufmin[n - j]);
        int amax = max(premax[i - 1], sufmax[n - j]);
        ans = min(ans, amax - amin);
    }
    cout << ans << endl;
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