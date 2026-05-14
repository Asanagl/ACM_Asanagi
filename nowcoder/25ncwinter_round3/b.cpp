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
    int n ;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int m = min(n, 30LL);
    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            if (__gcd(v[i], v[j]) > 1)
            {
                cout << v[i] << " " << v[j] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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