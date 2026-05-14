#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 998244353;

int64 mod_pow(int64 base, int64 exp) {
    int64 res = 1 % MOD;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % MOD;
        base = (__int128)base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        uint64_t k0;
        cin >> n >> k0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        if (k0 == 0) 
        {
            cout << 0 << '\n';
            continue ;
        }
        
        uint64_t value = k0;
        int64 shift = 0;
        while ((value & 1ULL) == 0) {
            value >>= 1;
            shift++;
        }
        
        bool is_zero = false;
        for (int i = 0; i < n; ++i) {
            if (is_zero || value == 0) {
                is_zero = true;
                break;
            }
            
            if ((i + 1) % 2 == 1) {
                shift += a[i];
            } else {
                int ai = a[i];
                if (shift >= ai) {
                    shift -= ai;
                } else {
                    int64 diff = ai - shift;
                    shift = 0;
                    if (diff >= 64) {
                        value = 0;
                        is_zero = true;
                    } else {
                        int d = (int)diff;
                        if ((value >> d) == 0) {
                            value = 0;
                            is_zero = true;
                        } else {
                            value >>= d;
                            int tz = __builtin_ctzll(value);
                            value >>= tz;
                            shift = tz;
                        }
                    }
                }
            }
        }
        
        if (is_zero || value == 0) {
            cout << 0 << '\n';
        } else {
            int64 ans = (value % MOD) * mod_pow(2, shift) % MOD;
            cout << ans % MOD << '\n';
        }
    }
    return 0;
}