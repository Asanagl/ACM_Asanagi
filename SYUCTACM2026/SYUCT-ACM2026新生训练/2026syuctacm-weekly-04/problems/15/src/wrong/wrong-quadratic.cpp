// 复杂度错误：对每个格子都完整重扫整个矩阵，统计"是否存在更靠前的元素不小于它"，
// 复杂度 O((nm)^2)。这里刻意不做提前退出，保证每个格子都付出 O(nm) 的代价。
// 在 200x200 上约 1.6e9 次比较，会在近上限数据上超时。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<char>> first(n + 1, vector<char>(m + 1, 0));
    int answerRow = 1;
    int answerCol = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            bool better = false;
            for (int r = 1; r <= n; ++r) {
                for (int c = 1; c <= m; ++c) {
                    const bool earlier = (r < i) || (r == i && c < j);
                    if (a[r][c] > a[i][j] || (a[r][c] == a[i][j] && earlier)) {
                        better = true;
                    }
                }
            }
            first[i][j] = better ? 0 : 1;
        }
    }

    long long best = a[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!first[i][j]) {
                continue;
            }
            if (a[i][j] > best || (a[i][j] == best && (i < answerRow || (i == answerRow && j < answerCol)))) {
                best = a[i][j];
                answerRow = i;
                answerCol = j;
            }
        }
    }

    cout << best << ' ' << answerRow << ' ' << answerCol << '\n';
    return 0;
}
