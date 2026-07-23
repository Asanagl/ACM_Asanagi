#include <bits/stdc++.h>
using namespace std ;
#define int long long
void solve ()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ; 
    int s = 0 ;
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> v[i] ;
        s^= v[i] ;
    } 
    int loc[30]  = {0};
    int temp = ((1 << 30) - 1) ^ s ;
    for (int i = 0 ; i < n ; i++)
    {
        int x = v[i] & temp ;
        for (int j = 29 ; j >= 0 ; j--){
            if ((x >> j) & 1) {
                if (!loc[j]) {
                    loc[j] = x ;
                    break ;
                }else
                {
                    x ^= loc[j] ;
                }
            }
            // cout << loc[j] << endl ;
        }
    }
    int ans = 0 ;
    for (int i = 29 ; i >= 0 ; i--)
    {
        if ((ans ^ loc[i]) > ans)
        ans ^= loc[i];
    }
    // cout << ans << " " << s << endl ;
    cout << s + 2 * ans  << endl ;

}
signed main()
{
    int t ;
    cin >> t ;
    while (t--)
    solve();
} 