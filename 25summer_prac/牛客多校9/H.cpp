#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
const int MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr) ;
    int T;
    cin >> T;
    while (T--) {
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n);
        ll s = 0;
        i128 B = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s = (s + (a[i] % MOD)) % MOD;
            if (x == 1) continue;   
            ll rem = a[i] % x;
            B += (i128)(a[i] / x);
            ll d;
            if (rem == 0) d = x;
            else d = x - rem;
            pq.push(d);
        }
        if (x == 1) {
            cout << s << endl;
            continue;
        }
        i128 F = B;         
        i128 cnt = 0;  
        while (F > 0 || (!pq.empty() && pq.top() == 1)) {
            ll d = pq.top();
            if (d < x) {
                ll need = d - 1;       
                if (F >= need) {
                    cnt += d;
                    F -= need;
                    pq.pop();
                    pq.push(x); 
                } else {
                    cnt += F;
                    F = 0;
                    break;
                }
            } else {
                ll step = x - 1;       
                i128 c = F / step;
                i128 r = F % step;
                cnt += c * x + r;
                F = 0;
                break;
            }
        }

        ll ans = (s - ((x - 1) % MOD) * (ll)(cnt % MOD) % MOD + MOD) % MOD;
        cout << ans << endl;
    }
}
