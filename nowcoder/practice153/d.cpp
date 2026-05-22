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
const int N = 4096 ;
using ll = long long ;
int addmod(int a, int b, int mod) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
void Asanagi() 
{
    int n, mod;
    cin >> n >> mod;
    vector<int> v(N);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    // 前缀和优化dp
    //  前缀和（异或）
    vector<int> prefix(N, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = (prefix[i - 1] ^ v[i]);

    // best[i][x] : 对于前j 个元素 ， 最后一段异或和 <= x的最优状态
    vector<vector<PII>> best(n + 1, vector<PII>(N + 1));
    for (int i = 0; i <= N; i++)
        best[0][i] = {0, 1 % mod};
    // tmp[i] 最后一段异或和 = x的状态数
    vector<PII> tmp(N + 1);

    for (int i = 1; i <= n; i++) 
    {
        for (int x = 0; x <= N; x++)
            tmp[x] = {-1, 0};
        for (int j = 0; j < i; j++) 
        {
            int x = (prefix[i] ^ prefix[j]) % mod;
            const PII &prev = best[j][x];
            if (prev.first < 0)
                continue;
            int cnt = prev.first + 1;
            if (cnt > tmp[x].first) {
                tmp[x] = {cnt, prev.second};
            } else if (cnt == tmp[x].first) {
                tmp[x].second = addmod(tmp[x].second, prev.second, mod);
            }
        }

        PII cur = {-1, 0};
        for (int x = 0; x <= N; x++) {
            if (tmp[x].first > cur.first) {
                cur = tmp[x];
            } else if (tmp[x].first == cur.first && tmp[x].first >= 0) {
                cur.second = addmod(cur.second, tmp[x].second, mod);
            }
            best[i][x] = cur;
        }
    }
    PII ans = best[n][N];
    cout << ans.first << ' ' << ans.second % mod << endl;
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
