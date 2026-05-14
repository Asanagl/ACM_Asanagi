#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int V , n ;
    cin >> V >> n ;
    vector <int> v (35) ;
    for (int i = 1 ; i <= n ; i ++) 
        cin >> v[i] ;
    vector <vector <int>> dp (35 , vector<int> (20005 , 0)) ;
    for (int i = 1; i <= n ; i ++)
    {
        for (int j = 0 ; j <= V ; j++)
        {
            if(j >= v[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << V - dp[n][V] ;
}