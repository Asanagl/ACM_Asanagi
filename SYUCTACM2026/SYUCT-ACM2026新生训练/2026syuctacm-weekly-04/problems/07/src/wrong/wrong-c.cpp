#include <bits/stdc++.h>

using namespace std;

// 实现错误：镜像下标写成 n - i 而不是 n - 1 - i，
// 把末尾之后的位置当作镜像字符，长度 >= 2 的串几乎全部被判成 NO。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = static_cast<int>(s.size());
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
