#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int n, m;
vector<int> G[MAXN][26];
int dis[MAXN][MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        char ch;
        cin >> u >> v >> ch;
        G[u][ch - 'a'].push_back(v);
        G[v][ch - 'a'].push_back(u);
    }
    memset(dis, 0x3f, sizeof(dis));
    queue<pair<int, int>> q;
    dis[1][n] = 0;
    q.push({1, n});
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        
        for (int c = 0; c < 26; c++) {
            for (int uu : G[u][c]) {
                for (int vv : G[v][c]) {
                    if (dis[uu][vv] == INF) {
                        dis[uu][vv] = dis[u][v] + 1;
                        q.push({uu, vv});
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dis[i][i] * 2);
    }
    for (int u = 1; u <= n; u++) {
        for (int c = 0; c < 26; c++) {
            for (int v : G[u][c]) {
                ans = min(ans, dis[u][v] * 2 + 1);
            }
        }
    }
    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    
    return 0;
}