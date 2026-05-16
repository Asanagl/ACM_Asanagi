#include <bits/stdc++.h>
using namespace std;

using ll = long long ;
void Asanagi() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    vector<bool> falg(n + 2, false);
    for (int x : v) if (x <= n) falg[x] = true;
    int k = 0;
    while (falg[k]) k++;
    int M = *max_element(v.begin(), v.end());
    if (k == 0) 
    {
        cout << 1LL * n * M << endl;
        return;
    }
    auto ysnb = [&](const vector<int>& seq) -> ll {
        vector<int> dis(k + 2, 0);
        ll maxcur = 0, mexcur = 0, sum = 0;
        for (int x : seq) {
            if (x > maxcur) maxcur = x;
            if (x <= k) {
                dis[x]++;
                while (dis[mexcur]) mexcur++;
            }
            sum += mexcur + maxcur;
        }
        return sum;
    };
    auto cnb = [&](bool max_first) -> vector<int> {
        auto f = mp;   // copy
        vector<int> fq;
        if (max_first) {
            fq.push_back(M);
            f[M]--;
            for (int i = 0; i < k; ++i) {
                if (M == k - 1 && i == k - 1) continue;
                fq.push_back(i);
                f[i]--;
            }
        } else {
            for (int i = 0; i < k; ++i) {
                fq.push_back(i);
                f[i]--;
            }
            if (M >= k) {
                fq.push_back(M);
                f[M]--;
            }
        }
        for (auto& [val, cnt] : f)
            for (int i = 0; i < cnt; ++i)
                fq.push_back(val);
        return fq;
    };
    ll ans = max(ysnb(cnb(false)), ysnb(cnb(true)));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) Asanagi();
}