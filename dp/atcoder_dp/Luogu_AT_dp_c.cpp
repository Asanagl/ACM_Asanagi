#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n ;
    cin >> n ;
    vector <vector <int>>v (n,vector<int>(3)) ;
    for (int i = 0 ; i < n ; i++) cin >> v[i][0] >> v[i][1] >> v[i][2] ;
    vector <vector<int>> dp (n , vector<int>(3 , 0)) ;
    dp[0][0] = v[0][0] ;
    dp[0][1] = v[0][1] ;
    dp[0][2] = v[0][2] ;
    for (int i = 1 ;i < n ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            if (j==0) dp[i][j] = v[i][j] + max (dp[i-1][1],dp[i-1][2]) ;
            else if (j==1) dp[i][j] = v[i][j] + max (dp[i-1][0],dp[i-1][2]) ;
            else if (j==2) dp[i][j] = v[i][j] + max (dp[i-1][0],dp[i-1][1]) ;
        }
    }
    int ans = max ({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) ;
    cout << ans ;
}