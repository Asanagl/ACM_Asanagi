#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 5e5 + 8;

vector<int> prime;
int minp[INF];
array<array<int, 2>, 2> f[INF]; // f[素因子p][最大0/次大1][颜色0/值1]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    minp[1] = 1;
    for (int i = 2; i < INF; i++) {
        if (!minp[i]) {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto p : prime) {
            if (i * p >= INF) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }

    int n;
    cin >> n;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        vector<int> factor;
        while (w[i] > 1) {
            int x = minp[w[i]];
            while (w[i] % x == 0) {
                w[i] /= x;
            }
            factor.push_back(x);
        }

        int res = 1;
        for (auto x : factor) { 
            if (c[i] != f[x][0][0]) {
                res = max(res, f[x][0][1] + 1);
            }
            if (c[i] != f[x][1][0]) {
                res = max(res, f[x][1][1] + 1);
            }
        }
        for (auto x : factor) { 
            if (c[i] != f[x][0][0]) {
                if (res > f[x][0][1]) {
                    f[x][1] = f[x][0];
                    f[x][0] = {c[i], res};
                } else if (res > f[x][1][1]) {
                    f[x][1] = {c[i], res};
                }
            } else {
                if (res > f[x][0][1]) {
                    f[x][0] = {c[i], res};
                }
            }
            assert(f[x][0][0] != f[x][1][0]);
        }
        ans = max(ans, res);
    }
    cout << ans << endl;

    return 0;
}