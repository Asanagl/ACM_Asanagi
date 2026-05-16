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

void Asanagi()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> f(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i - 1] == '0')
        {
            ++cnt;
            if (cnt == k)
            {
                f[i] = f[i - 1] + 1;
                cnt = 0;
            }
            else
            {
                f[i] = f[i - 1];
            }
        }
        else
        {
            cnt = 0;
            f[i] = f[i - 1];
        }
    }
    vector<int> ans(n + 1);
    int L = 0;
    for (int x = 0; x <= n; ++x)
    {
        while (L < n && f[L + 1] <= x) ++L;
        ans[x] = L;
    }

    for (int x = 0; x <= n; ++x)
    {
        cout << ans[x] << endl;
    }
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}