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

int comp(int n, int a, int b, int k)
{
    if (k < 0 || k > n / 7)
        return -1;
    int m = n - 7 * k;
    int t = min(m, k);
    int T = t + (m - t) / 2;
    return a * k + b * T;
}

void Asanagi()
{
    int n, a, b;
    cin >> n >> a >> b;
    int k0 = 0LL;
    int k1 = n / 8LL;
    int k2 = (n + 7LL) / 8LL;
    int k3 = n / 7LL;
    vector<int> candidates = {k0, k1, k2, k3};
    int best = 0;
    for (int it : candidates)
    {
        if (it >= 0 && it <= n / 7)
        {
            int val = comp(n, a, b, it);
            if (val > best)
                best = val;
        }
    }
    for (int i = -1; i <= 1; ++i)
    {
        int k = k1 + i;
        if (k >= 0 && k <= n / 7)
        {
            int val = comp(n, a, b, k);
            if (val > best)
                best = val;
        }
        k = k2 + i;
        if (k >= 0 && k <= n / 7)
        {
            int val = comp(n, a, b, k);
            if (val > best)
                best = val;
        }
    }
    cout << best << endl;
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