#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long calc(const vector<int>& a, int c) {
    int n = (int)a.size() + 1;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < c; ++i) cnt[a[i]]++;
    for (int i = c; i < n - 1; ++i) {
        if (cnt[a[i]] > 0) {
            for (int j = 0; j < c; ++j) cnt[a[j]]--;
            return 0;
        }
    }
    for (int i = 0; i < c; ++i) cnt[a[i]]--;

    int i = 0, j = n - 2;
    long long ans = 1;
    int idx = 1, prev = -1;

    while (i < c || j >= c) {
        int x;
        if (j < c) {
            x = a[i++];
        } else if (i >= c) {
            x = a[j--];
        } else {
            if (a[i] <= a[j]) x = a[i++];
            else x = a[j--];
        }

        if (x == prev) {
            long long ways = x - idx + 1;
            if (ways <= 0) return 0;
            ans = ans * ways % MOD;
        } else {
            prev = x;
        }
        ++idx;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n - 1);
        bool bad = false;
        for (int i = 0; i < n - 1; ++i) {
            cin >> a[i];
            if (a[i] < 1 || a[i] >= n) bad = true;
        }
        if (bad) {
            cout << 0 << '\n';
            continue;
        }

        vector<bool> pre(n - 1, false), suf(n - 1, false);
        if (n - 1 > 0) {
            pre[0] = true;
            for (int i = 1; i < n - 1; ++i)
                pre[i] = pre[i - 1] && (a[i] >= a[i - 1]);

            suf[n - 2] = true;
            for (int i = n - 3; i >= 0; --i)
                suf[i] = suf[i + 1] && (a[i] >= a[i + 1]);
        }

        int maxVal = *max_element(a.begin(), a.end());
        int L = -1, R = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == maxVal) {
                if (L == -1) L = i;
                R = i;
            }
        }

        vector<int> cand = {0, n - 1, L, R + 1};
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());

        long long ans = 0;
        for (int c : cand) {
            if (c < 0 || c > n - 1) continue;

            bool left_ok = (c == 0) || pre[c - 1];
            bool right_ok = (c == n - 1) || suf[c];
            bool boundary_ok = (c == 0 || c == n - 1) || (a[c - 1] != a[c]);

            if (left_ok && right_ok && boundary_ok) {
                ans = (ans + calc(a, c)) % MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
