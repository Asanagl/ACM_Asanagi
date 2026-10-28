#include <bits/stdc++.h>

using namespace std;

// 思路层：读错题意，把两条对角线的输出顺序写反（先副后主）。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

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

    cout << antiSum << '\n' << mainSum << '\n';
    return 0;
}
