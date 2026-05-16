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
    int m, n, z;
    cin >> m >> n >> z;
    if (m >= z)
    {
        cout << '0';
        return;
    }
    int s = m + n;
    int t1 = (z + n + s - 1) / s;
    int t2 = (z + s - 1) / s;

    if (t1 <= t2)
    {
        cout << '0';
    }
    else
    {
        cout << '1';
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
            Asanagi();
        }
    return 0;
}