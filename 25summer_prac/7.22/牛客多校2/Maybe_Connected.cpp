#include <bits/stdc++.h>
using namespace std ;
void solve ()
{
    int n , m ;
    cin >> n >> m ;
    int ans = 0 ;
    if (m <= n-1 && m >= 1)
    {
        ans = (m-1) * m /2 ;
    } else if (n == 1)
    {
        ans = 0 ;
    } else 
    {
        ans = (n-2) * (n - 1) / 2 - (m - n + 1) ;
    }
    cout << ans << endl ;
}
int main ()
{
    int t ;
    cin >> t; 
    while (t--) solve () ;
}