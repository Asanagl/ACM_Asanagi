#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;          // >> 自动跳过空白，无需处理 CRLF 的 '\r'

    const size_t pos = s.find(t);
    if (pos == string::npos) {
        cout << -1 << '\n';
    } else {
        cout << static_cast<long long>(pos) << '\n';
    }
    return 0;
}
