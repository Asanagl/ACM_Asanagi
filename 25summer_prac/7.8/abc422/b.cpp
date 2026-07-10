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
const int dx[4] = {0 , 0 , 1 , -1} ;
const int dy[4] = {1 , -1 , 0 , 0} ;

int g[25][25];
void Asanagi()
{
    memset (g , 0 , sizeof g) ;
    int n , m ;
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            char ch ;
            cin >> ch ;
            if (ch == '#') g[i][j] = 1 ;
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
            {
                if (g[i][j] == 0) continue ;
                int sum = 0 ;
                for (int z = 0 ; z < 4 ; z++)
                {
                    if (g[i+dx[z]][j+dy[z]]==1) sum++ ; 
                }
                if (sum != 2 && sum != 4) {
                    cout << "No" << endl ;
                    return;
                }
            }
    }
    cout << "Yes" ;
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
