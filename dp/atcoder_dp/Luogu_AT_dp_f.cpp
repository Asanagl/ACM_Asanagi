#include <bits/stdc++.h>
using namespace std ;
int main () 
{
    string s , t ;
    cin >> s >> t ;
    int ls = s.size() ;
    int lt = t.size ();
    int idxi , idxj ;
    vector <vector<int>> dp (ls+1 , vector <int> (lt+1,0)) ;
    for (int i = 1 ; i <= ls ; i++) // len
    {
        for (int j = 1; j <= lt ; j++)
        {
            int idxi = i-1 ;
            int idxj = j-1 ;
            if (s[idxi]==t[idxj]) dp[i][j] = dp[i-1][j-1]+1 ;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
        }
    }
    // traceability
    int len = dp[ls][lt] ;
    vector <char> ans ;
    int i = ls , j = lt ;
    while (!(i==0||j==0))
    {
        int idxi = i-1 ;
        int idxj = j-1 ;
        if (s[idxi]==t[idxj]) 
        {
            ans.push_back(s[idxi]);
            i-- ; j--;
        }
        else {
            if (dp[i-1][j]==dp[i][j])
            i-- ;
            else j-- ;
        }
    }
    while(ans.size()){
        cout <<ans.back();
        ans.pop_back();
    }
}