#include <bits/stdc++.h>
using namespace std ;

const int abx[4] = {1 , 0 , -1 , 0} ;
const int aby[4] = {0 , -1 , 0 , 1} ;

int main ()
{
    string str ;
    cin >> str ;
    int t  ;
    cin >> t ;
    int temp  = t ;
    int x = 0 , y = 0 ;
    int ch ;
    // * t <= str.size (len)
    for (auto &it : str)
    {
        if (t == 0)
            break;
        if (it == 'N')
            ch = 3;
        if (it == 'W')
            ch = 2;
        if (it == 'S')
            ch = 1;
        if (it == 'E')
            ch = 0;
        x += abx[ch], y += aby[ch] ;
        t--;
    }

    if (temp <= str.size())
    cout << x << " " << y ;
    else 
    {
        int cnt = t / str.size() ;
        int nw = t % str.size() ;
        x += cnt*x , y += cnt * y ;
        for (auto &it : str)
    {
        if (nw == 0)
            break;
        if (it == 'N')
            ch = 3;
        if (it == 'W')
        
            ch = 2;
        if (it == 'S')
            ch = 1;
        if (it == 'E')
            ch = 0;
        x += abx[ch], y += aby[ch] ;
        nw--;
    }
    cout << x << " " << y ;
    }
}