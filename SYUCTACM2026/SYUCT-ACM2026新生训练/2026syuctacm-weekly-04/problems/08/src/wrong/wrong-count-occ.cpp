#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    long long count = 0;
    size_t pos = s.find(t);
    while (pos != string::npos) {
        ++count;
        pos = s.find(t, pos + 1);
    }
    cout << count << '\n';
    return 0;
}
