#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int N = 105;
const int M = 5005;

struct Edge {
    int u, v;
    double w;
    bool operator<(const Edge &o) const {
        return w < o.w;
    }
} e[M];

int fa[N], n, m, cnt;
double ans;
pdd a[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

double dist(pdd A, pdd B) {
    double dx = A.fi - B.fi;
    double dy = A.se - B.se;
    return sqrt(dx * dx + dy * dy);
}

void solve() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf", &a[i].fi, &a[i].se);
        }
        m = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double d = dist(a[i], a[j]);
                if (d >= 10.0 && d <= 1000.0) {
                    e[++m] = {i, j, d * 100.0};
                }
            }
        }
        sort(e + 1, e + m + 1);
        for (int i = 1; i <= n; i++) fa[i] = i;
        cnt = 0;
        ans = 0;
        for (int i = 1; i <= m; i++) {
            int fu = find(e[i].u), fv = find(e[i].v);
            if (fu != fv) {
                fa[fu] = fv;
                ans += e[i].w;
                cnt++;
                if (cnt == n - 1) break;
            }
        }
        if (cnt != n - 1) {
            puts("oh!");
        } else {
            printf("%.1f\n", ans);
        }
    }
}

int main() {
    solve();
    return 0;
}