#include <bits/stdc++.h>

using namespace std;

// 独立参考解：由未接触主解的盲审实现改编而来，采用 0 基下标与流式读入。
// 主解使用 1 基下标，两者下标体系与循环写法不同，可交叉验证。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    long long diag = 0;
    long long anti = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long x;
            cin >> x;
            if (j == i) {
                diag += x;
            }
            if (j == n - 1 - i) {
                anti += x;
            }
        }
    }

    cout << diag << '\n' << anti << '\n';
    return 0;
}
