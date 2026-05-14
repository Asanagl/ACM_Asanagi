#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long

int n, m;

bool check(int mid)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int x = min(mid, sum + 1);
        sum += x;
        if (sum >= n)
            return true;
    }
    return sum >= n;
}

void solve()
{
    cin >> n >> m;

    if (m < 60 && (1LL << m) - 1 < n)
    {
        cout << -1 << endl;
        return;
    }

    int l = 1, r = n;
    int ans = n;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}

signed main() {
    IOS;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
