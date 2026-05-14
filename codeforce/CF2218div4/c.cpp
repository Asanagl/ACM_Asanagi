#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int lc = 0, rc = 0, mix = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '(' && b[i] == '(')
            ++lc;
        else if (a[i] == ')' && b[i] == ')')
            ++rc;
        else
            ++mix;
    }
    if (2 * lc + mix != n)
        return false;
    int ysnb = 0, mcnb = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '(' && b[i] == '(') {
            ++ysnb;
            ++mcnb;
        } else if (a[i] == ')' && b[i] == ')') {
            --ysnb;
            --mcnb;
            if (ysnb < 0 || mcnb < 0) return false;
        } else {
            if (ysnb < mcnb) {
                ++ysnb;
                --mcnb;
            } else {
                --ysnb;
                ++mcnb;
            }
            if (ysnb < 0 || mcnb < 0) return false;
        }
    }
    return ysnb == 0 && mcnb == 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
}


