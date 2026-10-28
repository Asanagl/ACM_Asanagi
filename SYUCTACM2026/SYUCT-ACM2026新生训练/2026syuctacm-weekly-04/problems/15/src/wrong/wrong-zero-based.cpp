// 实现错误：内部用 0 起始下标，输出时忘记加 1。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    long long best = a[0][0];
    int bestRow = 0;
    int bestCol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > best) {
                best = a[i][j];
                bestRow = i;
                bestCol = j;
            }
        }
    }

    cout << best << ' ' << bestRow << ' ' << bestCol << '\n';
    return 0;
}
