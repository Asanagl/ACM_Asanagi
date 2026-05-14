#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;



int longestsonstring(char *a, int a_l, char *b, int b_l) {
    int dp[a_l][b_l];
    int ans = 0;
    for (int i = 0; i < a_l; i++) {
        for (int j = 0; j < b_l; j++) {

            if (a[i] == b[j]) {
                if (i >= 1 && j >= 1)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
                
            }
            if (dp[i][j] > ans) {
                ans = dp[i][j];
            }

            // cout << ans << endl ;
        }
    }

    return ans;
}
void solve()
{
    string s, t;
    cin >> s >> t;
    
    int n = s.size(), m = t.size();
    int ans = 0;
    s = s + s;
    t = t + t;
    vector<vector<int>> dp(n * 2, vector<int>(m * 2, 0));
    
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < m * 2; j++) {
            if (s[i] == t[j]) {
                if (i > 0 && j > 0) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 1;
                }
                int len = min(dp[i][j], min(n, m));
                ans = max(ans, len);
            }
        }
    }
    
    cout << ans << endl;
}

signed main()
{
    IOS;
    int t =1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}