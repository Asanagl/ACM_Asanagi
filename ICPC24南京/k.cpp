#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k, w;
        cin >> n >> m >> k >> w;

        vector<pair<int, int>> a(n + m + 2);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = { x, 1 };
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            a[i + n] = { x, 0 };
        }
        a[n + m] = { w + 1, 0 };
        sort(a.begin(), a.end());

        bool ok = 1;
        vector<int> anss;
        int L = 0, R = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i].second) continue;   // 跳过红点
            L = R, R = i;
            vector<int> ans;
            for (int j = L + 1; j < R; j++) {
                int tmp = a[j].first;
                ans.push_back(tmp);
                while (j + 1 < R && a[j + 1].first < tmp + k) j++;
            }
            if (ans.empty()) continue;
            ans.push_back(a[R].first);  // 最后一个不能超过右边界
            for (int j = ans.size() - 1; j; j--) {
                if (ans[j - 1] > ans[j] - k) {
                    ans[j - 1] = ans[j] - k;  // 有重叠就移动
                }
            }
            if (ans[0] <= a[L].first) {  // 第一个不能超过左边界
                ok = 0;
                break;
            }
            ans.pop_back();
            for (auto x : ans) {
                anss.push_back(x);
            }
        }

        if (!ok) {
            cout << -1 << endl;
        } else {
            cout << anss.size() << endl;
            for (auto x : anss) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
