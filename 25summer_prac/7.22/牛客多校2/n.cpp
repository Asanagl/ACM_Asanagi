#include<bits/stdc++.h>
using namespace std;
#define int long long
const int LINF = LLONG_MIN ;
void solve ()
{
    int n , k ;
    cin >> n >> k ;
    vector <int> v (n+1) ;
    vector <int> pref (n+1) ;
    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> v[i] ;
    }
    sort(v.begin() , v.end()) ;
    for (int i = 1; i <= n ; i++)pref[i] = pref[i-1] + v[i] ;
    if ( k == 1 && k == 2 )
    {
        cout << pref[n] << endl ;
        return ;
    }
    int ans = 0 ;
    if (k % 2 == 1)
    {
        ans = LINF ;
        int l = pref[k/2] ;
        for (int i = 1 + k / 2 ; i <= n - k / 2 ; i++)
        {
            int r = pref[i + k/2] - pref[i-1];
            ans = max (ans , pref[n] - l - r + k * v[i]) ;
        }
    }
    if (k % 2 == 0)
    {
        ans = LINF;
        int l = pref[k / 2 - 1] ;
        for (int i = k / 2 ; i <= n - k/2 ; i++)
        {
            int mid = v[i] + v[i+1] ;
            int r = pref[i + k/2] - pref[i-1];
            ans = max (ans , pref[n] - l - r + k / 2 * mid) ;
            // cout << ans ;
        }
    }
    cout << ans << endl ;
}
signed main() {
    int t ;
    cin >> t ;
    while (t--) solve() ;
}