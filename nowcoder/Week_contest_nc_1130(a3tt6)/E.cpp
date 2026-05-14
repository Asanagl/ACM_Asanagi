#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200005;
vector<int> g[MAXN];
vector<int> tree[MAXN];

void dfs(int u, int parent, vector<int>& nodes) {
    nodes.push_back(u);
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u, nodes);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        vector<int> nodes;
        dfs(i, 0, nodes);
        tree[i] = nodes;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> sub = tree[i];
        if (sub.size() == 1) {
            cout << 0 << " ";
            continue;
        }

        vector<int> leaves;
        for (int u : sub) {
            int child_cnt = 0;
            for (int v : g[u]) {
                if (find(sub.begin(), sub.end(), v) != sub.end()) {
                    child_cnt++;
                }
            }
            if (child_cnt == 0) {
                leaves.push_back(u);
            }
        }

        map<int, int> depth_count;
        for (int u : sub) {
            if (find(leaves.begin(), leaves.end(), u) == leaves.end()) {
                int d = 0;
                queue<pair<int, int>> q;
                q.push({i, 0});
                vector<bool> visited(n + 1, false);
                visited[i] = true;
                while (!q.empty()) {
                    auto [node, dep] = q.front(); q.pop();
                    if (node == u) {
                        d = dep;
                        break;
                    }
                    for (int v : g[node]) {
                        if (!visited[v] && find(sub.begin(), sub.end(), v) != sub.end()) {
                            visited[v] = true;
                            q.push({v, dep + 1});
                        }
                    }
                }
                depth_count[d]++;
            }
        }

        if (depth_count.empty()) {
            cout << 0 << " ";
        } else {
            int max_depth = depth_count.rbegin()->first;
            cout << depth_count[max_depth] << " ";
        }
    }
    cout << endl;

    return 0;
}