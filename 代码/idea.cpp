#include <bits/stdc++.h>
using namespace std ;
const long long INF = 1e18+1 ;
int main ()
{
    #define int long long 
    int n , v  ;
    cin >> n >> v ;
    int c , w ;
    int maxw = 1000*n ;
    vector <int> f (1000*n+1 , INF) ;
    f[0] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> c >> w  ;
        // cout <<w<<endl;
        for (int j = maxw ; j >=w ;j--)
        {
            f[j] = min (f[j],f[j-w]+c) ;
        }
    }
    for(int i=maxw;i;--i){
        if(f[i]<=v){
            cout<<i;
            // cout <<f[i]<<" "<<i<<" ";
            return 0;
        }
    }
}