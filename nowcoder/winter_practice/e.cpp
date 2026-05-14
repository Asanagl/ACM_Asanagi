#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &it : a) cin >> it;

    int press = a[k-1];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= press && a[i] > 0) {
            ans++;
        }
    }
    cout << ans << endl;
}