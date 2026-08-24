#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// 666分讨来了你们聊
int min_people(ll T, ll u, ll v, ll m) {
    if (u <= T && v <= T && u + v + m <= 2 * T) return 0;
    if ((v <= T && u + m > T) || (u <= T && v + m > T)) return 1;
    return 2;
}
int max_people(ll T, ll u, ll v, ll m) {
    ll Lu = max(0LL, T - u);
    ll Lv = max(0LL, T - v);
    if (Lu + Lv < m) return 2;
    if ((v <= T && u + m > T) || (u <= T && v + m > T)) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll m;
        cin >> n >> m;
        vector<ll> v(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> v[i];
        ll mint = v[0] + m;   
        ll maxt = v[0];    
        int minx = 0, maxn = 0;
        if (v[1] > mint) minx++;
        if (v[1] + m > maxt) maxn++;
        for (int i = 2; i + 1 < 2 * n; i += 2) 
        {
            ll r = v[i], l = v[i + 1];
            minx += min_people(mint, r, l, m);
            maxn += max_people(maxt, r, l, m);
        }
        cout << minx << " " << maxn << endl;
    }
}
