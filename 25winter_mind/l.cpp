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
    int x;
    cin >> x;
    if (x > 45)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> wei;
    for (int i = 9; i >= 1; i--)
    {
        if (x >= i)
        {
            wei.push_back(i);
            x -= i;
        }
    }
    if (x > 0)
    {
        cout << -1 << endl;
        return;
    }
    sort(wei.begin(), wei.end());
    for (int d : wei)
    {
        cout << d;
    }
    cout << endl;
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