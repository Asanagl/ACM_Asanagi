#include <bits/stdc++.h>
using namespace std ;
void solve ()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ;
    bool flag1 = false;
    bool flag2 = false ;
    for (int i = 0 ; i < n ; i++ )
    {
        cin >> v[i] ;
        if (v[i] >= 3) flag1 = true ;
    }
    sort (v.begin() , v.end());
    for (int i = 1 ; i < n ; i++)
    {
        if (v[i-1]>=2 && v[i] >= 2)
        flag2 = true ;
    }
    if (flag1 || flag2) 
    {
        cout << "YES" << endl ;
    } else 
    {
        cout << "NO" << endl ;
    }
}
int main ()
{
    int t;
    cin >> t ;
    while  (t--)
    solve ();
}