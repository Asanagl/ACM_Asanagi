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
const int maxn = 2e5+10 ;
using ll = long long ;
int n, k, m;
bool use[maxn];
map<int, bool> mp;
struct node {
	int c, v;
} a[maxn];
bool cmp(node x, node y) {
	return x.v > y.v;
}
void Asanagi()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].c >> a[i].v;
    sort(a + 1, a + n + 1, cmp);
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n && cnt < m; i++) {
    	if (mp[a[i].c]) continue;
    	cnt++;
    	use[i] = true;
    	mp[a[i].c] = true;
    	ans += a[i].v;
	}
	int cntk = m;
    for (int i = 1; i <= n && cntk < k; i++) {
    	if (use[i]) continue;
    	cntk++;
    	ans += a[i].v;
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
