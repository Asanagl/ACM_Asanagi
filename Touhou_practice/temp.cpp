#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    int A, B;
    cin >> n >> m >> A >> B;
    vector<int> v(n);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int mr = 0;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') {
                mr |= (1 << j); 
            }
        }
        v[i] = mr;
    }
    
    const int VMARIX = 1 << m;
    vector<int> cnt_pop(VMARIX);
    vector<long long> w(VMARIX); 
    
    for (int mr = 0; mr < VMARIX; ++mr) {
        cnt_pop[mr] = __builtin_popcount(mr);
        long long sum = 0;
        for (int j = 0; j < m; ++j) {
            if (mr & (1 << j)) {
                sum += 1LL * B * (j + 1);
            }
        }
        w[mr] = sum;
    }
    long long sumB = 0;
    for (int j = 1; j <= m; ++j) sumB += 1LL * B * j;
    vector<long long> llv_cofA(n);      // A * (i+1)
    vector<long long> llvsum_cost(n); // m * A * (i+1) + sumB
    for (int i = 0; i < n; ++i) {
        llv_cofA[i] = 1LL * A * (i + 1);
        llvsum_cost[i] = 1LL * m * llv_cofA[i] + sumB;
    }
    
    long long ans = LLONG_MIN;
    for (int colmr = 0; colmr < VMARIX; ++colmr) {
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            int cntmr = v[i] ^ colmr;
            long long nofilp = 1LL * cnt_pop[cntmr] * llv_cofA[i] + w[cntmr];
            long long flip = llvsum_cost[i] - nofilp;
            total += max(nofilp, flip);
        }
        ans = max(ans, total);
    }
    cout << ans << endl;
}