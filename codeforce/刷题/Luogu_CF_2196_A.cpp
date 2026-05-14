#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    #define int long long 
    int t ;
    cin >> t ;
    while(t--){
    int p, q; cin >> p >> q;
    cout << (p < q && (q - p) * 2 <= p? "Bob\n" : "Alice\n");
}}
