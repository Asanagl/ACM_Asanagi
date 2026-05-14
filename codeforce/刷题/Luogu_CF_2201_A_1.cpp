#include <bits/stdc++.h>
using namespace std ;
void Asanagi ()
{
    int n ;
    cin >> n ;
    vector <int> v (n+10) ;
    vector <int> dic (n+10,0) ;
    vector <int> idx (n+10) ;
    for (int i = 1; i <= n ; i++)
    {
        cin >> v[i] ;
        idx[i] = i+1 ;
    }
    int ans = n ;
    for (int i = n ; i >= 1 ; i-- )
    {
        if (dic[i]) continue ;
        int j = idx[i] ;
        while (v[j]==v[i]+1) 
        {
            dic[j] = 1 ;
            idx[i] = idx[j] ;
            j = idx[j] ;
        }
    }
    for (int i = 1 ; i <= n ; i++)
    ans -= dic[i] ;
    cout << ans << endl ;
}
int main ()
{
    int t ;
    cin >> t ;
    while (t--)
    Asanagi () ;
}