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
int cnt[1000000] , f[1000000] ;

void Asanagi()
{
    
    int n , k , m ;
    cin >> n >> m >> k ;
    for (int i = 0 ; i <= k ; i ++)
    {
        f[i] = 0 ; cnt[i] = 0 ;
    }
    int max1 = 0 , max2 = 0 , ans = 0 , sm = 0 ;
    map<pair<int , int> , int> mp ;
    for (int i = 0 ; i < n ; i++)
    {
        int it ;
        cin >> it ;
        f[it] = 1 ;
    }
    for (int i = 0 ; i < m ; i++)
    {
        int u , v ;
        cin >> u >> v  ;
        if (u == v) 
        {
            if (f[u]){
                sm++;
                continue ;
            }
            cnt[u]++ ;
            continue ;
        }
        else if (f[u] && f[v])
            sm++ ;
        else if (f[u] && (!f[v]))
            cnt[v]++ ;
        else if ((!f[u]) && f[v])
            cnt[u]++ ;
        else mp[{min(u,v) , max(u,v)}] ++ ;
    }
    for (int i = 1 ; i <= k ; i++)
    {
        if (!f[i])
        {
            if (cnt[i]>max1)
            {
                max2 = max1 ;
                max1 = cnt[i];
            } else if (cnt[i] > max2)
            {
                max2 = cnt[i] ;
            }
        }
    }
    ans = sm + max1 + max2 ;
    for (auto &it : mp)
    {
        int a = it.first.first , b = it.first.second , c = it.second ;
        ans = max ({ans , sm+cnt[a] + cnt[b] + c}) ;
    }
    cout << ans << endl; 
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
