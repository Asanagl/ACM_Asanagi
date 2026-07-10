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
int graph[1010][1010] ;
bool drug = false ;
int ans = 0 ;
void run(int sx, int sy)
{
    
}
void Asanagi()
{
    int n , m ;
    cin >> n >> m ;
    memset (graph , 0 , sizeof graph) ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <=m ; j++)
        {
            char it ;
            cin >> it ;
            if (it == '.') continue;
            if (it == '#') graph[i][j] = -1 ;
        }
    }
    run(1,1) ;
    

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
