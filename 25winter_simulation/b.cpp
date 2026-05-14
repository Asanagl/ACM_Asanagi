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
    vector <int> a(4);
    for (auto &i: a) cin >> i ;
    int n , m ;
    n = max(a[0],a[1]) ;
    m = max(a[2],a[3]) ;
    sort(a.begin(),a.end()) ;
    if ((n == a[3] || n == a[2]) &&( m == a[3]|| m == a[2] ))
    cout << "YES" << endl ;
    else cout << "NO" << endl ;

}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}