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
#define PDD pair<ld , ld>
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
const int N = 1010 ;

int fa[N] , siz[N] ;

int find (int n)
{
    if(fa[n] == n) return n ;
    else return fa[n] = find(fa[n]) ; 
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (siz[x] > siz[y])
    {
        fa[y] = x;
        siz[x] += siz[y];
    }
    else
    {
        fa[x] = y;
        siz[y] += siz[x];
    }
}

struct graph {
    int u, v;

    ld w;
} pic[105];

ld dist(PDD A, PDD B) {
    ld dx = A.first - B.first;
    ld dy = A.second - B.second;
    return sqrt(dx * dx + dy * dy);
}
void Asanagi() {
    int cnt, n, m;
    ld ans = 0;
    memset(fa, 0, sizeof fa);
    memset(siz, 0, sizeof siz);
    cin >> n;
    for (int i = 1; i <= 1000; i++) {
        fa[i] = i;
        siz[i] = 1;
    }
    PDD a[N];
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    m = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ld d = dist(a[i], a[j]);
            if (d >= 10.0 && d <= 1000.0) {
                pic[++m] = {i, j, d * 100.0};
            }
        }
    }
    sort(pic + 1, pic + m + 1, [](graph a, graph b) { return a.w < b.w; });
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    cnt = 0;
    ans = 0;
    for (int i = 1; i <= m; i++) {
        int fu = find(pic[i].u), fv = find(pic[i].v);
        if (fu != fv) {
            fa[fu] = fv;
            ans += pic[i].w;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }
    if (cnt != n - 1) {
        cout << "oh!" << endl;
    } else {
        cout << fixed << setprecision(1) << ans << endl;
    }
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
