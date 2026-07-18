#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 10;
int t, n, x, y, p[N], fa[N], rk[N];
bool flag;

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rk[x] < rk[y]) fa[x] = fa[y];
    else if (rk[x] == rk[y]) fa[x] = fa[y], ++rk[y];
    else fa[y] = fa[x];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    for (cin >> t; t; --t) {
        flag = false;
        cin >> n >> x >> y;
        for (int i = 1; i <= n; ++i) cin >> p[i];
        fill(rk + 1, rk + n + 1, 1);
        iota(fa + 1, fa + n + 1, 1);
        for (int i = 1; i <= x; ++i)
            for (int j = i; j <= n; j += x) merge(i, j);
        for (int i = 1; i <= y; ++i)
            for (int j = i; j <= n; j += y) merge(i, j);
        for (int i = 1; i <= n; ++i) if (find(i) != find(p[i])) {
            flag = true;
            break;
        } cout << (flag ? "NO\n" : "YES\n");
    } return 0;
}