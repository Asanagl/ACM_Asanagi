#include <bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
const int N = 1e5+10 ;
vector <int>  maxn (33 , 1);
vector <int> donate (N , 1) ;
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
    for (int i = 1 ; i <= N - 10 ; i++)
    {
        donate[i] = calc(i) ;
    }
}
void solve()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ;
    vector <int> v_c (n) ;
    vector <int> qi_idx  ;
    bool flag = false ;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
        v_c[i] = v[i] ;
        if (v[i] % 2 == 1 )
        {
            flag = true ;
            qi_idx.pb(v[i]) ;
        }
    }
    int odd_cnt = 0 ;
    if (flag) 
    {
        for (int i = 0 ;i < n ; i ++)
        {
            odd_cnt += donate[v[i]] ;
        }
    }
    // * type 1 donate^(i+j) > donate^i + j
    int odd_ans = 0 ;
    for (int i = 0 ;i < n ; i++)
    {
        int it = v[i] ;
        int bir_idx = upper_bound(maxn.begin(), maxn.end() , it) - maxn.begin() ;
        int bir = maxn[bir_idx] ;
        if (donate[bir] > donate[it] + (bir - it) ) 
        {
            v_c[i] = bir ;
            
        }
    }
}
signed main ()
{
    init() ;
    int t ;
    cin >> t ;
    while (t--)
    solve () ;
}