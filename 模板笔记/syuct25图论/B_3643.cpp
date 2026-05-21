#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
// #define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
// const int INF = 1e9+10;
// const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

struct node 
{
    int du = 0 ;
    set<int> son ;
};
int a[1005][1005] ;
node b[1005] ;
void Asanagi()
{
    int n , m ;
    cin >> n >> m ;
    
    memset (a, 0 , sizeof a) ;
    for (int i = 1 ; i <= m ; i ++)
    {
        int u ,v ;
        cin >> u >> v ;
        a[u][v] = 1 ;
        a[v][u] = 1 ;
        b[u].du++ , b[v].du++ ;
        b[u].son.insert(v) ;
        b[v].son.insert(u) ;
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        for (int j = 1 ; j <= n ; j ++)
        cout << a[i][j] << " " ; 
        cout << endl ;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        cout << b[i].du << " ";
        for (auto &it : b[i].son)
        {
            cout << it << " ";
        }
        cout << endl ;
    }

}

signed main()
{
    IOS;
    int t = 1;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}