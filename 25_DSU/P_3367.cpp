#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const int N = 2e5 + 10 ;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

int fa[N] , siz[N] ;
int find (int n)
{
    if(fa[n] == n) return n ;
    else return fa[n] = find(fa[n]) ; 
}

void Asanagi()
{
    int n , m  ;
    cin >> n >> m ;
    for (int i = 1 ; i <= n ;i++)
    {
        fa[i] = i ; siz[i] = 1 ;
    }
    for (int i = 0 ;i < m ; i ++)
    {
        int op , x , y ;
        cin >> op >> x >> y ;
        if (op == 1) 
        {
            x = find(x) ; y = find(y) ;
            if (x==y) continue ;
            if (siz[x] > siz[y]) 
                {
                    fa[y] = x ;
                    siz[x] += siz[y];
                }
                else 
                {
                    fa[x] = y ;
                    siz[y] += siz[x] ;
                }
            
        } else 
        {
            x = find(x) ;
            y = find(y) ;
            if(x==y) cout << "Y" << endl ;
            else cout << "N" << endl ;
        }
    }
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}