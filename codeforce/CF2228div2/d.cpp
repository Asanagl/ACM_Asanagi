#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void Asanagi() {
    int n;
    cin >> n;
    vector<pair<int, int>> pts(n);
    vector<int> ys;
    ys.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].first >> pts[i].second;
        ys.push_back(pts[i].second);
    }
    sort(pts.begin(), pts.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int p = (int)ys.size();

    vector<int> cnt(n + 2, 0);
    for (auto &[x, y] : pts) cnt[y]++;

    int minr = 1, maxr = n;
    while (minr <= n && cnt[minr] == 0) minr++;
    while (maxr >= 1 && cnt[maxr] == 0) maxr--;

    int minl = n + 1, maxl = 0;
    ll ans = 0;

    for (int i = 0; i < n; ) {
        int j = i;
        int cc = pts[i].first;
        while (j < n && pts[j].first == cc) {
            int y = pts[j].second;
            minl = min(minl, y);
            maxl = max(maxl, y);
            cnt[y]--;
            if (cnt[y] == 0) {
                if (y == minr) {
                    while (minr <= n && cnt[minr] == 0) minr++;
                }
                if (y == maxr) {
                    while (maxr >= 1 && cnt[maxr] == 0) maxr--;
                }
            }
            j++;
        }
        if (j < n) {
            int l = max(minl, minr);
            int h = min(maxl, maxr);
            if (l < h) {
                int lb = (int)(upper_bound(ys.begin(), ys.end(), l) - ys.begin());
                int ub = (int)(lower_bound(ys.begin(), ys.end(), h) - ys.begin());
                int left = max(0, lb - 1);
                int right = min(p - 2, ub - 1);
                if (left <= right) ans += (ll)(right - left + 1);
            }
        }
        i = j;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) Asanagi();
    return 0;
}