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
const int MOD =998244353 ;
const int N  = 2500 ;
void Asanagi()
{
    int n ;
    cin >> n ;
    vector<int> v;
    int len = 0 ;
    if (n == 1) 
    {
        cout << 1 << endl ;
        return ;
    }
    for (int i = 1 ;i < sqrt(n) ; i++)
    {
        if (n % i == 0 )
        {
            v.pb(i);
            v.pb(n / i) ;
            len+=2 ;
        }
    }
    if (sqrt(n) * sqrt(n) == n) {
        len++ ; v.pb(sqrt(n)) ;
    }
    int k = len ;
    sort(v.begin() , v.end()) ;
    unordered_map<int , int> ump ;
    for (int i = 0 ; i < k ; i++)
        ump[v[i]] = i ;
    int dp0[15][N] ;
    int dp1[15][N] ;
    vector <int> fact (15 , 1) ;
    for (int i = 1 ;i <= 14 ; i++)
    {
        fact[i]= i * fact[i-1] ;
        fact[i]%=MOD ;
    }
    memset(dp0 , 0 , sizeof dp0) ;
    memset(dp1 , 0 , sizeof dp1) ;
    dp0[0][ump[1]] = 1 ;
    for (auto &it : v)
    {
        int old0[15][N], old1[15][N];
        memcpy(old0, dp0, sizeof(dp0));
        memcpy(old1, dp1, sizeof(dp1));
        for (int i = 1 ; i <= 14 ; i++ )
        {
            for (int j = 0 ; j < k ; j++)
            {
                int c = v[j] ;
                if (c % it == 0)
                {
                    long long prev = c / it;
                    int prev_idx = ump[prev];

                    dp0[i][j] = (dp0[i][j] + old0[i-1][prev_idx]) % MOD;

                    dp1[i][j] = (dp1[i][j] 
                        + old1[i-1][prev_idx] 
                        + old0[i-1][prev_idx] * it % MOD) % MOD;
                }
            }
        }
    }
    int ans = 0;
    int idx_N = ump[n];

    for (int b = 1; b <= 14; ++b) {
        ans = (ans + dp1[b][idx_N] * fact[b] % MOD) % MOD;
    }

    cout << ans << endl;

    
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
