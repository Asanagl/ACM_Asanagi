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

void solve()
{
    int n ;
    cin >> n ;
    int cnt = 0 ;
    while (n--)
    {
        int x = 3 ;
        int solve = 0 ;
        while (x--)
        {
            int a ;
            cin >>a ;
            if (a == 1) solve++;
        }
        if (solve >= 2) {
            cnt++;

    }
    cout << cnt << endl;
}


signed main()
{
    IOS;
    int t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}