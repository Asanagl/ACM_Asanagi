#include <bits/stdc++.h>
using namespace std ;
void Asanagi ()
{
    int a , b ,c ,d ;
    cin >> a >> b >> c >> d ;
    if (b > c || a > d) 
    cout << c-a + d-b << endl ; 
    else
    cout << abs(a-b) + abs(min(c,d)-max(a,b)) + abs (c-d) << endl ;
}
int main ()
{
    int t ;
    cin >> t ;
    while (t--)
    Asanagi () ;
}