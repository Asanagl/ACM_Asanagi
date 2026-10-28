#include <bits/stdc++.h>

using namespace std;

// 主解：按行流式读入，用两个互相独立的 if 分别累加主、副对角线。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    long long mainSum = 0;
    long long antiSum = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long x;
            cin >> x;
            if (j == i) {
                mainSum += x;
            }
            if (j == n + 1 - i) {
                antiSum += x;
            }
        }
    }

    cout << mainSum << '\n' << antiSum << '\n';
    return 0;
}
