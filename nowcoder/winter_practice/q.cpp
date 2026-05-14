#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll groups ;
    cin >> groups ;
    ll x , y ,z ; 
    ll a , b , c ;
    while (groups--)
    {
        cin >> x >> y >> z ;
        a += x ;
        b += y ;
        c += z ;
    }
    cout << (a == 0 && b == 0 && c == 0 ? "YES" : "NO") << endl;
}