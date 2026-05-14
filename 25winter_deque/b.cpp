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
    int n;
    cin >> n;
    int cnt = 0;
    cnt += n / 100;
    n %= 100;
    cnt += n / 20;
    n %= 20;
    cnt += n / 10;
    n %= 10;
    cnt += n / 5;
    n %= 5;
    cnt += n;
    cout << cnt << endl;
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