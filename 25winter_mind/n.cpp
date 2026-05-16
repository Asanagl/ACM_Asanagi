#include <bits/stdc++.h>
using namespace std;

vector<int> cand(int x, int n) {
    vector<int> res;
    for (int d = 2; d <= 4; d++) {
        if (x - d >= 1) res.push_back(x - d);
        if (x + d <= n) res.push_back(x + d);
    }
    return res;
}

bool cmp(int start, int n, vector<int>& ans) {
    vector<bool> used(n + 1, false);
    ans.clear();
    ans.push_back(start);
    used[start] = true;
    int cur = start;
    for (int i = 1; i < n; i++) {
        vector<int> cand = cand(cur, n);
        int nxt = -1;
        for (int x : cand) {
            if (!used[x]) {
                nxt = x;
                break;
            }
        }
        if (nxt == -1) {
            return false;
        }
        ans.push_back(nxt);
        used[nxt] = true;
        cur = nxt;
    }
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(ans[i] - ans[i + 1]);
        if (diff < 2 || diff > 4) {
            return false;
        }
    }
    return true;
}

void Asanagi() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    for (int start = 1; start <= n; start++) {
        if (cmp(start, n, ans)) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " \n"[i == n - 1];
            }
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        Asanagi();
    }
    return 0;
}