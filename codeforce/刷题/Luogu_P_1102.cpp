#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void solve()
{
    int n , c ;
    cin >> n >> c ;
    int ans = 0 ;
    vector <int> v (n) ;
    for (int i = 0 ; i < n ;i++)
        cin >> v[i]  ;
    sort (v.begin(), v.end()) ;
    for (int i = 0 ; i < n ; i++)
    {
        ans+=(upper_bound(v.begin() , v.end(), v[i]+c) ) - (lower_bound(v.begin() , v.end() , v[i]+c)) ;
    }
    cout << ans << endl ;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}