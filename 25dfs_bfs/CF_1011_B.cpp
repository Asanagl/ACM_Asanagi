#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
const int dx[8] = {1,0,-1,0,1,-1,1,-1} ;
const int dy[8] = {0,1,0,-1,1,-1,-1,1} ;
int n , m ;
int vis[110][110] ;
int ysnb[110][110] ;
bool cmp(int x,int y){
	return x>y;
}
void solve()
{
    int n, m;
    int cnt[105];
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    sort(cnt + 1, cnt + 1 + n, cmp);
    for (int i = 100; i >= 1; i--)
    {
        int tmp = 0;
        for (int j = 1; j <= 100; j++)
            tmp += cnt[j] / i;
        if (tmp >= n)
        {
            cout << i;
            return;
        }
    }
    cout << 0;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}