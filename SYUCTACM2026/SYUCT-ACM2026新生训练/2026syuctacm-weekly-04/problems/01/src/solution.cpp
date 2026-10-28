#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const size_t len = s.size();
    cout << len << ' ' << s[0] << ' ' << s[len - 1] << '\n';
    return 0;
}
