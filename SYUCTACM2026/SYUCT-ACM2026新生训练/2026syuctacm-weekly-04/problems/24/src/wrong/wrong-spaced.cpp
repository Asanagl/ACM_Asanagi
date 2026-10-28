// 错解 E（实现层：输出格式错误）：颜色判断完全正确，但每个字符后面多打一个空格，
// 每行长度变成 2m-1，不符合"每行一个长度为 m 的字符串"。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (((i + j) % 2 == 0) ? 'A' : 'B') << ' ';
        }
        cout << '\n';
    }
    return 0;
}
