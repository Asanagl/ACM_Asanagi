#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n ;
    cin >> n ;
    int x ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x ;
        if (x >= 0 ) {
            cout << "No" << endl ;
            return 0 ; 
        }
    }
    cout << "Yes" << endl ;
}