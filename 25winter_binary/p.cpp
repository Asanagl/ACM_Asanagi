#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    int n ;
    cin >> n ;
    vector<int> a(n) , b(n) , c(n) ;
    for (auto &it : a) cin >> it ;
    for (auto &it : b) cin >> it ;
    for (int i = 0 ; i < n ; i++ )
    c[i] = a[i] - b[i] ;
    sort(c.begin(),c.end()) ; 
    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        int x = -c[i];
        auto pos = upper_bound(c.begin() + i + 1, c.end(), x) ;
        if (pos != c.end()) 
        {
            ans += c.end() - pos;
        }
    }
    cout << ans << endl;
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