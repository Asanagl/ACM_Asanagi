#include <bits/stdc++.h>
using namespace std ;
#define int long long
void solve ()
{
    int n , c ;
    cin >> n >> c ;
    vector <int> v (n) ;
    for (auto &it : v) cin >> it ;
    sort (v.begin() , v.end()) ;
    int ans = 0 ;
    for (int i = 0 ; i < n ; i ++)
    ans+=(upper_bound(v.begin() , v.end(), v[i]+c) ) - (lower_bound(v.begin() , v.end() , v[i]+c)) ;
    cout << ans << endl ;
}
signed main ()
{
    int t = 1 ;
    // cin >> t ;
    while (t--) solve() ;
}