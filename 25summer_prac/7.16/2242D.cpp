#include <bits/stdc++.h>
using namespace std ;
void solve()
{
    string a , b ;
    int suma = 0 , sumb = 0 ;
    cin >> a >> b ;
    int lena = a.size() , lenb = b.size() ;
    suma = (int)a[0] - '0' ;
    sumb = (int)b[0] - '0' ;
    vector <int> prefixa (lena+1 , 0 ) ;
    vector <int> prefixb (lenb+1 , 0 ) ;
    prefixa[1] = suma ;
    prefixb[1] = sumb ;
    for (int i = 1 , n = lena ; i < n ; i++)
    {
        suma = (suma + (int)(a[i] - '0')) % 10 ;
        prefixa[i+1] = suma ;
    }
    for (int i = 1 , n = lenb ; i < n ; i++)
    {
        sumb = (sumb + (int)(b[i] - '0')) % 10 ;
        prefixb[i+1] = sumb ;
    }
    if (suma != sumb) { cout << -1 << endl ; return;}
    
    // LCS 
    int dp[lena+1][lenb+1] ;
    memset (dp , 0 , sizeof dp) ;
    for (int i = 1 ; i <= lena ; i++)
    {
        for (int j = 1; j <= lenb ; j++)
        {
            if (prefixa[i] == prefixb[j])
            dp[i][j] = dp[i-1][j-1] + 1 ;
            else dp[i][j] = max (dp[i-1][j] , dp[i][j-1]) ;
        }
    }
    cout << dp[lena][lenb] << endl ;
    
    
}
int main ()
{
    int t ;
    cin >> t ;
    while  (t--)
    solve ();
}