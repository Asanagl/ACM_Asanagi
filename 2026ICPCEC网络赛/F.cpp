#include <bits/stdc++.h>
using namespace std ;

int main ()
{
    #define int long long 
    int n , m ;
    cin >> n >> m ;
    int cnt = 0 , pass = 0 ;
    int ans = 0 ;
    for (int i = 0 ; i < n ; i ++)
    {
        cnt = 0 ;
        for (int j = 0 ; j < m ; j++)
        {
            int it = 0 ;
            cin >> it ;
            cnt += it ;
        
        }
        if (cnt < pass) ans++ ;
        pass = cnt ;
    } 
    cout << ans << endl ;
}
