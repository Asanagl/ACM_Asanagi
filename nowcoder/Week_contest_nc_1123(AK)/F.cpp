#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;
    BIT(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int idx, long long val) {
        for (int i = idx; i <= n; i += i & -i) bit[i] += val;
    }
    long long sum(int idx) const {
        long long res = 0;
        for (int i = idx; i > 0; i -= i & -i) res += bit[i];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        vector<int> freq(n + 1, 0);
        for (int x : a) freq[x]++;
        
        int max_freq = 0;
        for (int v = 1; v <= n; ++v) max_freq = max(max_freq, freq[v]);
        
        BIT bit_cnt(max_freq);
        BIT bit_sum(max_freq);
        
        int total = 0;
        long long best = 0;
        
        for (int m = 1; m <= n; ++m) {
            if (freq[m] == 0) continue;
            
            int c = freq[m] - 1;
            long long sum_small = 0;
            int cnt_large = total;
            
            if (c >= max_freq) {
                sum_small = bit_sum.sum(max_freq);
                cnt_large = 0;
            } else if (c > 0) {
                sum_small = bit_sum.sum(c);
                cnt_large = total - bit_cnt.sum(c);
            }
            
            long long keep = freq[m] + sum_small + 1LL * cnt_large * max(0, c);
            best = max(best, keep);
            
            int f = freq[m];
            bit_cnt.add(f, 1);
            bit_sum.add(f, f);
            total++;
        }
        
        cout << n - best << endl;
    }
    return 0;
}