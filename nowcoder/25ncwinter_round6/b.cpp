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
const int INF = 2048;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{

    int n;
    cin >> n;
    vector<int> a(INF), b(INF);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    bool dp[INF] = {false};
    dp[0] = true;
    for (int i = 0; i < n; ++i)
    {
        bool next[INF] = {false};
        for (int v = 0; v < INF; ++v)
        {
            if (!dp[v])
                continue;
            int v1 = (v >= a[i]) ? (v - a[i]) : 0;
            next[v1] = true;

            int v2 = v ^ b[i];
            next[v2] = true;
        }
        memcpy(dp, next, sizeof(dp));
    }
    int ans = 0;
    for (int v = INF - 1; v >= 0; --v)
    {
        if (dp[v])
        {
            ans = v;
            break;
        }
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
            Asanagi();
        }
    return 0;
}