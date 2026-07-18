#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n ;
    cin >> n ;
    int ans = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        int x , y ;
        cin >> x >> y ;
        string str;
        cin >> str ;
        if (str[0] == 'k')
        {
            ans += (y - x) ;
        } 
    }
    cout << ans ;
}