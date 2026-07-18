#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;

        if (k > m) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) {
                int a = m + (i % k) - ((i - 1) % k);
                cout << a << " " ;
            }
            cout << endl ;
        }
    }
}
