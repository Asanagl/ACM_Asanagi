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
const int N = 350 , M = 6005;
int n , m , u , v;
bool vis[N] , mp[N][N];
int matched[N] ;
int found(int x )
{
    for (int i = n + 1 ; i <= 2*n ; i ++)
    {
        if (!mp[x][i] || vis[i]) continue ;
        vis[i] = 1 ;
        if (!matched[i]||found(matched[i]))
        {
            matched[i] = x ;
            matched[x] = i ;
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
        memset(vis , 0 , sizeof (vis)) ;
        if (found(i)) ans++ ;
    }
    return ans;
}
void Sagiri(int x)
{
    x += n;                    
    do {
        printf("%d ", x = x - n);   
    } while (vis[x] = 1, x = matched[x]); 
    printf("\n");
}
void Asanagi()
{

    scanf ("%lld%lld",&n , &m) ;
    for (int i = 1 ; i <= m ; i ++)
    {
        int u , v ;
        scanf("%lld%lld",&u ,&v) ;
        mp[u][v+n] = 1  ;
    }
    int ans = n - match();
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (matched[i + n] == 0)
        {
            Sagiri(i);
        }
    }
    cout << ans << endl;
}

signed main()
{
    // IOS;
    int t = 1;    
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
