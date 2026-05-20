#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;
        vector <int> v (n+2) ; // 代表每一家的金额数量
        vector <int> dp (n+2 , 0) ; // 代表偷窃到第n家的状态（最大金额数）
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> v[i] ;
        }
        dp[1] = v[1] ;
        dp[2] = max (v[1] , v[2]) ;
        for (int i = 3 ; i <= n ; i++)
        {
            dp[i] = max (dp[i-2]+v[i] , dp[i-1]) ; 
        }
        cout << dp[n] << endl ;
    }  
}