#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

const int prefixes[6] = {1005, 1006, 1007, 1008, 1009, 1010};

void solve()
{
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    int ans = LINF;
    for (int k = 0; k <= 15; k++)
    {
        int y = x;
        for (int i = 0; i < k; i++)
        {
            y /= 10;
            if (y == 0)
                break;
        }
        if (y == 0)
        {
            y = 0;
        }

        int r = y % c;

        for (int p = 0; p < 6; p++)
        {
            int base = prefixes[p];
            int powten = 1;
            for (int m = 0; m <= 10; m++)
            {
                int z0 = base * powten;
                int L = max(z0, y);
                int R = z0 + powten;

                if (R <= y)
                {
                    powten *= 10;
                    continue;
                }
                int d = (r - (L % c) + c) % c;
                int z = L + d;
                if (z < R)
                {
                    int cost = k * a + ((z - y) / c) * b;
                    if (cost < ans)
                    {
                        ans = cost;
                    }
                }

                powten *= 10;
                if (powten > 1e18)
                    break;
            }
        }
    }

    cout << ans << endl;
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}