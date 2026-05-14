#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    #define int long long 
    int n , v  ;
    cin >> n >> v ;
    vector <int> c (n) ;
    vector <int> w (n) ; 
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> c[i] >> w [i] ;
    }
    vector <int> pack (v+1 , 0 ) ;
    for (int i = 0 ; i < n ; i++){
        for (int j = v ; j >= c[i];j--)
            pack[j] = max (pack[j], pack[j-c[i]]+w[i]) ;
    }
    cout << pack[v] ;
    
}