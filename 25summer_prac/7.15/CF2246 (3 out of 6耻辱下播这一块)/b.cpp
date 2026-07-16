#include <bits/stdc++.h>
using namespace std ;
#define int long long
void solve ()
{
    int n ;
    cin >> n ;
    if (n==2) {
        cout << -1 << endl ;
        return ;
    }
    if (n==1)
    {
        cout << 114514 << endl ;
        return ;
    }
    cout << "1 2 " ;
    int x = 3 ;
    for (int i = 0; i < n-2 ; i++)
    {
        cout << x <<" ";
        x *= 2 ;
    }
    cout << endl ;
}
signed main ()
{
    int t ;
    cin >> t ;
    while (t--) solve();
}