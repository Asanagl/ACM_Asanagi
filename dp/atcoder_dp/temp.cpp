#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    #define int long long
    int  n ;
    cin >> n ;
    vector <int> v (n) ;
    unordered_map <int , int> ump ;
    for (auto &it : v) 
    {
        cin >> it ;
        ump[it]++;
    }
    sort (v.begin(),v.end()) ;
    vector<int> dp (n+1 , 0) ;
    dp[0] = v[0] ;
    for (int i = 1 ; i < n ; i++)
    {
        dp[i] = max ( dp[i-1] , dp[i-1-ump[v[i]-1]] + v[i] );
    }
    cout << dp[n-1] ;
}