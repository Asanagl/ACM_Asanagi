#include <bits/stdc++.h>

using namespace std;

// 独立暴力：直接构造反转串后逐字符比较，不做双指针/镜像下标推导。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }

    string t(s.rbegin(), s.rend());
    bool ok = (t == s);
    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}
