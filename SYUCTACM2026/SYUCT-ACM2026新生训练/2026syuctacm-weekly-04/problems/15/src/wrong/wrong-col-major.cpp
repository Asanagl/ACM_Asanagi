// 思路错误：把"行优先"理解成"列优先"，外层循环列、内层循环行。
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

    long long best = a[1][1];
    int bestRow = 1;
    int bestCol = 1;
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
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
