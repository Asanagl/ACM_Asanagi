#include <bits/stdc++.h>
using namespace std ;
#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"

void Asanagi()
{
    ll a , b ,c ;
    cin >> a >> b >> c ;
    cout << min (a+b,min(a+c,b+c));

}

int main ()
{
    IOS ;
    int t = 1;
    // cin >> t ;
    while (t--)
    {
        Asanagi() ;
    }
}