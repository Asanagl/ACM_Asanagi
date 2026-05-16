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
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> x(105), y(105);
    for (int i = 0; i < m; ++i)
        cin >> x[i] >> y[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            bool trigger = false;
            for (int k = 0; k < m; ++k)
            {
                int dx = i - x[k];
                int dy = j - y[k];
                if (dx * dx + dy * dy <= r * r)
                {
                    trigger = true;
                    break;
                }
            }
            if (trigger)
                ans++;
        }
    }
    cout << ans << endl;
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