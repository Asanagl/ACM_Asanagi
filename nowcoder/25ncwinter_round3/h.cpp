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
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int c = xa * yb - xb * ya;
    int d = ya - yb;
    if (d == 0) {
        if (abs(c) == 4) {
            cout << "0.0" << endl;
        } else {
            cout << "no answer" << endl;
        }
    } else {
        ld x1 = (4.0 - c) / d;
        cout << fixed << setprecision(1000) << x1 << endl;
    }
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}