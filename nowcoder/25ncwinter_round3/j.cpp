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



int get_depth(ll x) {
    return 63 - __builtin_clzll(x);
} // 严肃誊抄板子中，，，，

void solve()
{

    int n, q;
    cin >> n >> q;
    int h = get_depth(n);
    int lly = n - (1LL << h) + 1;
    while (q--)
    {
        ll x;
        cin >> x;
        int d = get_depth(x);
        if (d < h)
        {
            cout << (1LL << d) << endl;
        }
        else
        {
            cout << lly << endl;
        }
    }
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