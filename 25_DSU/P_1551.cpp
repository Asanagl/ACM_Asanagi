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
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (siz[x] > siz[y])
    {
        fa[y] = x;
        siz[x] += siz[y];
    }
    else
    {
        fa[x] = y;
        siz[y] += siz[x];
    }
}

void solve()
{
    int n , m , p  ;
    cin >> n >> m >> p ;
    for (int i = 1 ; i <= n ;i++)
    {
        fa[i] = i ; siz[i] = 1 ;
    }
    for (int i = 0 ; i < m ; i++)
    {
        int x , y ;
        cin >> x >> y ; 
        merge(x , y) ;
    }
    for (int i = 0 ; i < p ; i ++)
    {
        int x , y ;
        cin >> x >> y ;
        x = find(x) , y = find(y) ;
        if (x==y) cout << "Yes" << endl  ;
        else cout <<"No" << endl ;
    }
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}