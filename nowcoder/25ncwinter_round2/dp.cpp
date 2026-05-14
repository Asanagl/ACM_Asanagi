#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353 ;
int main ()
{
    #define int long long 
    int n , m ;
    cin >> n >> m ;
    int dp[1010][1010] = {0};
    dp[1][1] = 1 ;
    for (int i = 1 ; i <1000 ; i++)
    {
        for (int j = 1; j < 1000 ; j ++)
        {
            if (i==1&&j==1) continue ;
            dp[i] [j] = (dp[i-1][j]+dp[i][j-1])%MOD ;
        }
    }
    cout <<dp[n][m];
}