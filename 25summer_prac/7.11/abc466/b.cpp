#include <bits/stdc++.h>
using namespace std ;
void solve ()
{
    int n ;
    cin >> n ;
    int m ;
    cin >> m ;
    unordered_map<int , int> ump ;
    for (int i = 1 ; i <= n ; i ++)
    {
        int x , y ;
        cin >> x >> y ;
        ump[x] = max (ump[x] , y) ;
    }
    for (int i = 1 ; i <= m ; i++)
    {
        if (ump[i] == 0)
        {
            cout << -1 << " " ;
        }
        else cout << ump[i] << " " ;
    }
}
int main ()
{
    solve () ;
}