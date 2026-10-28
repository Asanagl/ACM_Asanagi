#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int l = 0;
    int r = static_cast<int>(s.size()) - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            cout << "NO\n";
            return 0;
        }
        ++l;
        --r;
    }
    cout << "YES\n";
    return 0;
}
