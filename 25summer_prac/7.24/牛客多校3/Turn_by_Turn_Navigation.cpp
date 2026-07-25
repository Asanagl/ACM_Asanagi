#include <bits/stdc++.h>
using namespace std ;
void solve ()
{
    int n ;
    cin >> n ;
    int x1 , y1 , x2 , y2 ;
    cin >> x1 >> y1 ;
    pair<int , int> v1 ;
    pair<int , int> v2 ;
    for (int i = 1 ; i < n ; i ++)
    {
        if (i == 1) 
        {
            cin >> x2 >> y2 ;
            v1 = {x2-x1 , y2-y1} ;
            x1 = x2 , y1 = y2 ;
            continue ;
        }
    }
    
}
int main ()
{
    int t ;
    cin >> t ;
    while (t--)
    solve();
}