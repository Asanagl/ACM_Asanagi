#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    cout << static_cast<long long>(s.find(t[0])) << '\n';
    return 0;
}
