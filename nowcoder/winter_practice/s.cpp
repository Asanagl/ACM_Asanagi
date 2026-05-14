#include <bits/stdc++.h>
using namespace std ;
int main()
{
    #define ll long long 
    ll x ;
    cin >> x ;
    ll step = 0  ;
    for (int i = 5 ; i >=1 ; i--)
    {
        step += x / i ; 
        x %= i ;
    }
    cout << step << endl ;
    
}