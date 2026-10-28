#include <bits/stdc++.h>
using namespace std;
#define int long long 



void solve() {
    int n;
    int k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    auto check = [&](int x) -> bool {
        int sum = 0;
        for (int p = 1; p <= n; ++p) {
            sum += a[p - 1];
            if (sum >= x) {
                int m = n - p;
                if (x < m * (k - 1) + n) {
                    return false;
                }
            }
        }
        return true;
    };
    int low = 1, high = 1e18, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t ;
        while (t--) {
            solve();
        }
    
    return 0;
}
