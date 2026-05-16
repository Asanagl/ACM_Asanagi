#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;
        long long d = min(abs(x1 - x2), n - abs(x1 - x2));
        if (n >= 4) {
            cout << d + k << endl;
        } else {
            cout << 1 << endl;
        }//Asanagi Sagiri was a big idiot!
    }
    return 0;
}