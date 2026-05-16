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
     int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    
    vector<int> ans(n + 1, 0);
    for (int i = 1; i < m; ++i) {
        int x = a[i - 1];
        int y = a[i];
        if (x == y) continue;
        ans[1] += abs(x - y);
    }
    for (int i = 1; i < m; ++i) {
        int x = a[i - 1];
        int y = a[i];
        if (x == y) continue;
        if (x > y) swap(x, y);
        ans[x] += (y - 1) - abs(y - x);
        ans[y] += (x - 1) - abs(y - x);
        if (y - x > 1) {
            ans[x + 1] += abs(y - x - 1) - abs(y - x);
            ans[y] -= abs(y - x - 1) - abs(y - x);
        }
    }
    for (int i = 2; i <= n; ++i) {
        ans[i] += ans[i - 1];
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;222
}

signed main()
{
    IOS;
    int t =1 ;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}