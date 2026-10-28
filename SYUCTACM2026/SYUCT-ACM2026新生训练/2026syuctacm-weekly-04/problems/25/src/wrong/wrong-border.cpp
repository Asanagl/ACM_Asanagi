#include <bits/stdc++.h>

using namespace std;

// 思路层错解：用"最长前后缀"反推循环节，即答案是 n - 最长 border。
// 该结论只对"平移周期"成立；对整次重复的循环节并不成立，
// 例如 "abcab" 的最长 border 为 "ab"，会输出 3，但正确答案是 5。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    const int n = static_cast<int>(s.size());

    for (int len = n - 1; len >= 1; --len) {
        if (s.substr(0, len) == s.substr(n - len)) {
            cout << n - len << ' ' << s.substr(0, n - len) << '\n';
            return 0;
        }
    }

    cout << n << ' ' << s << '\n';
    return 0;
}
