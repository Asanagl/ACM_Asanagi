#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

int circle(int a , int b)
{
    int res = 0;
    for (int i = 2 ; i <= a ; i++)
    {
        res = (res + b) % i;
    }
    return res + 1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    cout << circle(n, m) << endl;
}

signed main()
{
    IOS;
    int t =1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}