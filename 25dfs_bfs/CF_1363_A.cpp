#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
void solve()
{
    int a, b, n, x;
    int k;
    cin >> n >> x;
    a = 0;
    b = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k;
        if (k & 1)
            a++;
        else
            b++;
    }
    if (a == 0)
    {
        cout << "No" << endl;
        return;
    }
    a--;
    x--;
    if (x & 1)
    {
        if (b == 0)
        {
            cout << "No" << endl;
            return;
        }
        b--;
        x--;
    }
    a = a / 2 * 2;
    if (a + b >= x)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}