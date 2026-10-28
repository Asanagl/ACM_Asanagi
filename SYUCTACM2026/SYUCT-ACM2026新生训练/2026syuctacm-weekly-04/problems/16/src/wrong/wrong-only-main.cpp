#include <bits/stdc++.h>

using namespace std;

// 思路层：只算并输出了主对角线之和，漏掉副对角线这一行输出。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long mainSum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long x;
            cin >> x;
            if (j == i) {
                mainSum += x;
            }
        }
    }

    cout << mainSum << '\n';
    return 0;
}
