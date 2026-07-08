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

void Asanagi()
{
    int l , d ;
    cin >> l >> d ;
    int t[3] ;
    cin >> t[0] >> t[1] >> t[2] ; 
    string str ;
    cin >> str ;
    vector <vector <int> > dp (l+1 , vector <int> (5 , LINF)) ;
     // dp[i][c] 指的是进行到第i位，高位处于c的最小时间
     // 状态转移 = dp[i][c] = min (dp[i-1][c] + t [str[i] - '0'] , dp[i-d][c-1]); 
     // 进行上述状态转移的前提是：c-1 >= 1 ;
     // 四维
    dp[0][4] = 0;
    for (int i = 1 ;i <= l ; i ++)
    {
        for (int c = 1 ; c <= 4 ; c++)
        {
            if (dp[i-1][c] == LINF) continue ;
            dp[i][c] = min (dp[i-1][c] + t[str[i-1] - '0']  , dp[i][c]) ;
            if (c >= 2 )
            {
                int temp = min (l , i+d-1) ;
                dp[temp][c-1] = min (dp[temp][c-1] , dp[i-1][c]) ;
            }
        }
    }
    int ans = LINF ;
    for (int i = 1 ; i < 5 ; i ++)
    {
        ans = min (ans , dp[l][i]) ;
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
