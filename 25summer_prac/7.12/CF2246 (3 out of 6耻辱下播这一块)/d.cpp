#include <bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
const int N = 1e5 + 10 ;
vector <int>  maxn (33 , 1);
vector <int> delam (N) ;
inline int calc (int x) 
{
    int res = 0 ;
    while (x != 0)
    {
        if (x % 2 == 0)
        {
            res++ ;
            x /= 2;
        }
        else 
        {
            res++ ;
            x-- ;
        }
    }
    return res ;
}
void init ()
{
    for (int i = 1 ; i <= 32 ; i++)
    {
        maxn[i] = (1<<(i)) ;
    }
}
void solve()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ;vector <int> change(n) ;
    int qi = 0 ; 
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> v[i] ;
        change[i] = v[i] ;
        if (v[i] % 2 == 1) qi++ ;
    }
    int ans = 0 ;
    // * type 1
    for (int i = 0 ; i < n ; i++)
    {
        int it = v[i] ;
        int bires_idx = upper_bound(maxn.begin() , maxn.end() , it) - maxn.begin() ;
        int bires = maxn[bires_idx] ;
        bires -= it ;
        // cout << it << " bires idx " << bires_idx << " bires " << bires << endl ;
        int c2 = calc (it) ;
        int c1 = calc (bires_idx + bires) ;
        if (c1 < c2) 
        {
            ans += bires ;
            change[i] = bires + it ;
            
        }
    }
    // * type 2 整体贡献对比
    for (int i = 0 ; i < n ; i++)
    {
        
    }
    while (1)
    {
        bool flag = false ;
        for (int i = 0 ; i < n ; i++)
        {
            change[i] /= 2 ;
            if (change[i] % 2 == 1) flag = true ;
        }
        ans++ ;
        if (flag) break ;
    }
    for (int i = 0 ; i < n ;i++)
        {
            ans += calc(change[i]) ;
        }
        cout << ans << endl; 
}
signed main ()
{
    init() ;
    int t ;
    cin >> t ;
    while (t--)
    solve () ;
}