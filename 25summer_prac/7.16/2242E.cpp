#include <bits/stdc++.h>
using namespace std ;
vector <int> bi (33 , 1) ;
void init ()
{
    for (int i = 0 ; i <= 32 ; i++)
    {
        bi[i] = (1 << i) ;
    }
}
void solve ()
{
    int l , r , n ;
    cin >> l >> r >> n ;
    int x , y ;
    x = lower_bound(bi.begin() , bi.end() , l) - bi.begin() ;
    y = lower_bound(bi.begin() , bi.end() , r) - bi.begin() ;
    // case1 /2 == >>1 ; %2 == 取最低位
    if (x == y)
    {
        int T = x ;
        vector <int> a (x) , b (y) ;
        for (int i = 0 ; i < x ; i++)
        {
            a[i] = l % 2 ;
            l /= 2 ;
            b[i] = r % 2 ;
            r /= 2 ;
        }
        int idxcg = 0 ;
        for (int i = 0 ; i < x ; i++)
        {
            if (a[i] == b[i]) continue ;
            else if (a[i] != b[i])
            {
                idxcg = i ;
                break ;
            }
        }
        vector <int> ans (x) ;
        for (int i = 0 ; i < n ; i ++)
        {
            if (i == idxcg)
            ans[i] = 0 ;
            else
            ans[i] = a[i] & b[i] ;
        }
        for (int i = 1 ; i <= n ; i++)
        {
            cout << ans[(i%x) - 1] << " " ;
        }
        cout << endl ;
    }
}
int main ()
{
    init();
    int t ;
    cin >> t ;
    while (t--) solve ();
}