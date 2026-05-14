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
    long long n, k;
    cin >> n >> k;
    if (n >= k && (n - k) % 2 == 0)
    {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; ++i)
        {
            cout << "1 ";
        }
        cout << n - (k - 1) << endl;
    }
    else if (n % 2 == 0 && n >= 2 * k)
    {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; ++i)
        {
            cout << "2 ";
        }
        cout << n - 2 * (k - 1) << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

signed main()
{
    IOS;
    int t;
    //  t = 1 ;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}