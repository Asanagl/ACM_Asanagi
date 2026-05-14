#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    long long N_min = 2LL * m;
    long long N_max = 1LL + m * (m + 1) / 2;

    if (n < N_min || n > N_max) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl ;

    long long S = N_max - n;
    vector<int> p(m);
    p[1] = 0;
    for (int d = m - 1; d >= 2; --d) {
        int max_val = d - 1;
        int take = min((long long)max_val, S);
        p[d] = take;
        S -= take;
    }
    vector<pair<int, int>> edges;
    int x = 2;
    vector<int> c(m + 1);
    c[0] = 1;
    for (int i = 1; i <= m; ++i) {
        c[i] = x++;
        edges.emplace_back(c[i - 1], c[i]);
    }

    for (int i = 1; i <= m - 1; ++i) {
        int a = c[p[i]];
        int l = i - p[i];
        int temp = a;
        for (int j = 1; j <= l - 1; ++j) {
            int mid = x++;
            edges.emplace_back(temp, mid);
            temp = mid;
        }
        int son = x++;
        edges.emplace_back(temp, son);
    }
    for (auto [u, v] : edges) {
        cout << u << ' ' << v << '\n';
    }

    return 0;
}