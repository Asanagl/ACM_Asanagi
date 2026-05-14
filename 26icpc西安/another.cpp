#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (ll &x : a) cin >> x;
        vector<ll> b(m), c(m);
        for (ll &x : b) cin >> x;
        for (ll &x : c) cin >> x;
        
        ll S = 0;
        for (ll x : a) S += x;
        
        multiset<ll> st(a.begin(), a.end());
        
        vector<pair<ll,ll>> tk; // (c, b)
        for (int i = 0; i < m; i++) {
            if (c[i] > b[i]) {
                tk.push_back({c[i], b[i]});
            }
        }
        sort(tk.begin(), tk.end(), [](auto &x, auto &y) {
            if (x.first != y.first) return x.first > y.first;
            return x.second < y.second;
        });
        
        ll gain = 0;
        vector<pair<ll,ll>> rem;
        
        for (auto &[ci, bi] : tk) {
            auto it = st.lower_bound(ci);
            if (it != st.end()) {
                gain += ci - bi;
                st.erase(it);
            } else {
                rem.push_back({bi, ci});
            }
        }
        
        sort(rem.begin(), rem.end());
        vector<ll> remA(st.rbegin(), st.rend());
        
        int i = 0, j = 0;
        while (i < (int)remA.size() && j < (int)rem.size()) {
            if (remA[i] > rem[j].first) {
                gain += remA[i] - rem[j].first;
                i++; j++;
            } else {
                break;
            }
        }
        
        cout << S - gain << "\n";
    }
}
