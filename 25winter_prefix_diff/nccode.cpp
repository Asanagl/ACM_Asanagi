#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &it : a) cin >> it ;
    vector<int> b = a;
    sort(b.begin(), b.end());
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        int target = m - a[i];
        int temp = upper_bound(b.begin(), b.end(), target) - b.begin();
        int ccn = temp;
        if (a[i] <= target) {
            ccn--;
        }
        ans[i] = (ll)a[i] * (2 * ccn - (n - 1));
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}