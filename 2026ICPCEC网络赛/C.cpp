#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
struct qu
{
    int l , r ;
    vector <int> q ;
};
void solve()
{
    int n , m ;
    cin >> n >> m ;
    vector <qu> q (m) ;
    for (int i = 0 ; i < m ; i ++)
    {
        int l , r ;
        cin >> l >> r ;
        q[i].l = l ;
        q[i].r = r ;
        for (int j = 0 ;  j <= r - l ; j++)
        {
            int it ;
            cin >> it ;
            q[i].q.pb(it) ;
        }
    }
    sort (q.begin() , q.end() , [](qu a , qu b) {return a.l < b.l && a.r < b.r;});
    qu pass ;
    reverse(q.begin() , q.end()) ;
    pass = q.back() ;
    q.pop_back() ;
    while (!q.empty())
    {
        qu cnt = q.back() ;
        q.pop_back() ;
        if (cnt.r == cnt.l) continue ; 
        if (pass.r > cnt.l )
        {
            int r = cnt.l , l = cnt.r ;
            int len = cnt.l - pass.r + 1 ;
            int passidx = 0 , cntidx = 0 ,need = 0 ;
            for (int i = passidx ; i < pass.q.size() ; i++)
            {
                int it = pass.q[i] ;
                if (l <= it && it <= r)
                {
                    for (int j = cntidx ; j < cnt.q.size() ; j++)
                    {
                        int cq = cnt.q[j] ;
                        if (cq == it)
                        {
                            need++ ;
                            break ;
                        }
                        cntidx = j ;
                    }
                }
                passidx = i ;
            }
            if (need != len) {cout << -1 << endl ; return ;}
            
        }
    }
}
int main ()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
