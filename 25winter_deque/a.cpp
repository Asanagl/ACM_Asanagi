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

void Asanagi()
{
    int x, y, a, b;
    cin >> x >> y;
    cin >> a >> b;

    x = abs(x);
    y = abs(y);
    if (x > y)
    {
        swap(x, y);
    }

    int it = (x + y) * a;
    int op = x * b + (y - x) * a;

    cout << min(it, op) << endl;
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