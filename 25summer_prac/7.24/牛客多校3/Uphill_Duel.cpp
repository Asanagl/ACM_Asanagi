#include <bits/stdc++.h>
using namespace std;

struct node {
    int h, id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int N = n * m;
        vector<int> h(N);
        vector<node> cells;
        cells.reserve(N);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int idx = i * m + j;
                cin >> h[idx];
                cells.push_back({h[idx], idx});
            }
        }

        sort(cells.begin(), cells.end(), [](const node& a, const node& b) {
            return a.h > b.h;
        });

        vector<char> win(N, 0);

        for (auto& it : cells) {
            int id = it.id;
            int r = id / m;
            int c = id % m;
            bool canWin = false;

            // 上
            if (r > 0) {
                int nid = id - m;
                if (h[nid] > h[id] && !win[nid]) canWin = true;
            }
            // 下
            if (r + 1 < n) {
                int nid = id + m;
                if (h[nid] > h[id] && !win[nid]) canWin = true;
            }
            // 左
            if (c > 0) {
                int nid = id - 1;
                if (h[nid] > h[id] && !win[nid]) canWin = true;
            }
            // 右
            if (c + 1 < m) {
                int nid = id + 1;
                if (h[nid] > h[id] && !win[nid]) canWin = true;
            }

            win[id] = canWin ? 1 : 0;
        }

        int q;
        cin >> q;
        while (q--) {
            int r, c;
            cin >> r >> c;
            r--; c--;
            int id = r * m + c;
            cout << (win[id] ? "First" : "Second") << endl;
        }
    }
}