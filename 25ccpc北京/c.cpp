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
const int LINF = 1e18 + 10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long;

void Asanagi()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0;; i++)
    {
        sum += 1LL << i;
        m--;
        if (m == 0)
        {
            if (sum >= n)
            {
                cout << (1LL << i) << endl;
                return;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        int x = (n - sum + m - 1) / m;
        if (x <= (1ll << (i + 1)))
        {
            cout << max(x, 1ll << i) << endl;
            return;
        }
    }
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
            Asanagi();
    }
    return 0;
}

