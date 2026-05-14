#include <bits/stdc++.h>
using namespace std ;

int main ()
{
    int n ;
    cin >> n ;
    int k ;
    cin >> k ;
    vector <int> v (n+10) ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> v[i] ;
    }
    vector <int> dp (n+10 , 0) ;
    for (int i = 2 ; i <= n ; i ++ )
    {
        dp[i] = 1061109567 ;
        for (int j = max(1,i-k) ; j < i ; j++)
        {
            dp[i] = min(dp[i] , dp[j]+abs(v[i]-v[j])) ;
        }
    }
    cout << dp[n] ;
}