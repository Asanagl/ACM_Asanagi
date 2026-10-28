#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    if (!(cin >> s)) return 0;
    string t(s.rbegin(), s.rend());
    cout << (t == s ? "YES" : "NO") << '\n';
    return 0;
}
