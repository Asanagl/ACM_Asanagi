#include <bits/stdc++.h>
using namespace std ;
const int INF = 1e5+5 ;
int main()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ;
    for (int i = 0 ; i < n ; i++)cin >> v[i] ;
    vector <int> dp (n) ;
    dp[0] = v[0] ;
    if (n==1) cout << v[1] ;
    for (int i = 1 ; i < n; i++ )
    {
        dp[i] = max(dp[i-1]+v[i],v[i]) ;
    }
    int ans = *max_element(dp.begin(), dp.end())  ;
    cout << ans ;
}