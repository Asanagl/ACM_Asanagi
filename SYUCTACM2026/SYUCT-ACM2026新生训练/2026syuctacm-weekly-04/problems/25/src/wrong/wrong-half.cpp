#include <bits/stdc++.h>

using namespace std;

// 思路层错解：只检查字符串能否对折成完全相同的两半。
// 若两半相等就输出 n/2，否则输出 n。
// 对折相等只是循环节的必要条件而非充分条件，
// 例如 "abcabcabcabc" 答案为 3，本解法输出 6；"aaaa" 答案为 1，本解法输出 2。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    const int n = static_cast<int>(s.size());

    if (n % 2 == 0 && s.substr(0, n / 2) == s.substr(n / 2)) {
        cout << n / 2 << ' ' << s.substr(0, n / 2) << '\n';
    } else {
        cout << n << ' ' << s << '\n';
    }

    return 0;
}
