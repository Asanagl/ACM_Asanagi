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
int g [510][510] ;
int prefix[510][510] ;
void Asanagi()
{
    int h , w , k ;
    cin >> h >> w >> k ;
    memset(g , 0 , sizeof g) ;
    memset(prefix , 0 , sizeof prefix) ;
    for (int i = 1 ; i <= h ; i ++)
    {
        for (int j = 1 ; j <= w ; j++)
        {
            char ch ;
            cin >> ch ;
            g[i][j] = ch -'0' ;
        }
    }
    prefix[1][1] = g[1][1] ;
    for (int i = 1; i <= h ; i++)
    {
        for (int j = 1 ; j <= w ; j++)
        {
            prefix[i][j] = g[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    int ans = 0 ;
    for (int i = 1 ; i <= h ; i ++)
    {
        for (int ii = i ; ii <= h  ; ii++)
        {
            for (int j = 1 ; j <= w  ; j++)
            {
                for (int jj = j ; jj <= w ; jj++)
                {
                    int res = 0 ;
                    res = prefix[ii][jj] - prefix[ii][j-1] - prefix[i-1][jj]+ prefix[i-1][j-1];
                    ans+= (res == k) ; 
                }
            }
        }
            
                
    }
    cout << ans << endl ;
    
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
