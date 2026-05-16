#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
// codeforce wocaonima
ull a;
int n;
vector<int> d;
string sa;
ull best, ans;

void upd(ull x) {
    ull diff = x > a ? x - a : a - x;
    if (diff < ans || (diff == ans && x < best)) {
        ans = diff;
        best = x;
    }
}
ull plz(int pos, int len, ull prefix, int digit) {
    for (int i = pos; i < len; i++) prefix = prefix * 10 + digit;
    return prefix;
}
void dfs(int pos, ull cur, bool less, bool greater, int len) {
    if (pos == len) { upd(cur); return; }
    if (greater) { upd(plz(pos, len, cur, d[0])); return; }
    if (less)    { upd(plz(pos, len, cur, d.back())); return; }

    int ysnb = sa[pos] - '0';
    auto it = lower_bound(d.begin(), d.end(), ysnb);
    if (it != d.end() && *it == ysnb)
        dfs(pos + 1, cur * 10 + ysnb, false, false, len);
    if (it != d.begin()) {
        int x = *(it - 1);
        if (pos > 0 || x != 0 || len == 1)
            upd(plz(pos + 1, len, cur * 10 + x, d.back()));
    }
    if (it != d.end() && *it != ysnb) {
        int y = *it;
        if (pos > 0 || y != 0 || len == 1)
            upd(plz(pos + 1, len, cur * 10 + y, d[0]));
    } else if (it != d.end() && *it == ysnb) {
        auto it2 = it + 1;
        if (it2 != d.end()) {
            int y = *it2;
            if (pos > 0 || y != 0 || len == 1)
                upd(plz(pos + 1, len, cur * 10 + y, d[0]));
        }
    }
}

void Asanagi() 
{
    cin >> a >> n;
    d.resize(n);
    for (int &x : d) cin >> x;
    sort(d.begin(), d.end());
    sa = to_string(a);
    int m = sa.size();
    best = 0;
    ans = ULLONG_MAX;
    if (m > 1) {
        if (d.back() != 0) {
            ull x = 0;
            for (int i = 0; i < m - 1; i++) x = x * 10 + d.back();
            upd(x);
        } else upd(0);
    } else {
        if (d[0] == 0) upd(0);
    }
    if (d[0] != 0) {
        ull x = 0;
        for (int i = 0; i < m + 1; i++) x = x * 10 + d[0];
        upd(x);
    } else if (n > 1) {
        ull x = d[1];
        for (int i = 1; i < m + 1; i++) x = x * 10 + d[0];
        upd(x);
    }
    dfs(0, 0, false, false, m);
    cout << ans << endl;
    // 我求你了我求你了我求你了我求你了我求你了我求你了我求你了我求你了我求你了我求你了我求你了我求你了我求你了我求你了我求你了我求你了
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) Asanagi();
    return 0;
}