#include <bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
void solve ()
{
    int n ;
    cin >> n ;
    vector <int> v (n+1 , 0 ) ;
    for (int i = 1 ;i <= n ;i ++)
    cin >> v[i] ;

    for (int i = 1 ; i < n ; i ++)
    {
        int d = v[i] - i ;
        v[i] = i ;
        v[i+1] += d ;
        if (d <= -1)
        {
            cout << "NO" << endl ;
            return ;
        }
    }
    int sum = accumulate(v.begin() , v.end() , 0LL) ;
    int tar = (n+1) * n  / 2 ;
    if (sum < tar) 
    {
        cout << "NO" << endl ;
        return ;
    }
    cout << "YES" << endl ;
    return ;

}
signed main ()
{
    int t ;
    cin >> t ;
    while (t--)
    solve () ;
} // 1 4 2 2
// 1 2 4 2
// 1 2 3 3