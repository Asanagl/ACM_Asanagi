#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    const size_t pos = s.rfind(t);
    if (pos == string::npos) {
        cout << -1 << '\n';
    } else {
        cout << static_cast<long long>(pos) << '\n';
    }
    return 0;
}
