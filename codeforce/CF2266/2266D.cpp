#include <bits/stdc++.h>
using namespace std ;
void solve ()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ;
    for (auto &it : v ) cin >> it ;
    vector <int> v1 = v ;
    for (int i = 0 ; i < n ; i++)
    {
        v1[i] = v[i] - (i+1) ;
    }
    int ans = 1 ;
    int maxn = 1 ;
    sort (v1.begin() , v1.end()) ;
    reverse (v1.begin() , v1.end()) ;
    int temp = v1[0] ;
    for (int i = 1 ; i < n ; i++)
    {
        if (temp == v1[i]) continue ;
        if (temp == v1[i]+1)
        {
            maxn++ ;
            ans = max (ans , maxn) ;
        } else maxn = 1;
        temp = v1[i] ;
        ans = max (ans , maxn) ;
    }
    cout << ans << endl ;
}
int main ()
{
    int t ;
    cin >> t ;
    while (t--)
    solve() ;
}
