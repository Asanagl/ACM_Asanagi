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
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
const int N = 550 ;
int n , m ,e , u , v;
int vis[N] , mp[N][N];
int matched[N] ;
int found(int x )
{
    for (int i = 1 ; i <= m ; i ++)
    {
        if (!mp[x][i] || vis[i]) continue ;
        vis[i] = 1 ;
        if (!matched[i]||found(matched[i]))
        {
            matched[i] = x ;
            return 1 ;
        }
    }
    return 0 ;
}

int match ()
{
    int ans = 0 ;
    for (int i = 1 ; i <= n ;i ++)
    {
        memset(vis , 0 , sizeof vis) ;
        if (found(i)) ans ++ ;
    }
    return ans ;

}

void Asanagi()
{
    cin >> n >> m >> e ;
    for (int i = 1 ; i <= e ; i ++)
    {
        cin >> u >> v ;
        mp[u][v]++ ;
    }
    cout << match();
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
