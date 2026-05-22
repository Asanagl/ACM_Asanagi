
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
	int n;
	vector<ll> c;
	BIT(int n = 0) { init(n); }
	void init(int n_) {
		n = n_;
		c.assign(n + 1, 0);
	}
	void add(int x, ll v) {
		for (; x <= n; x += x & -x) c[x] += v;
	}
	ll query(int x) {
		ll s = 0;
		for (; x; x -= x & -x) s += c[x];
		return s;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<ll> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	BIT bit(n);
	ll ys = 0;
	for (int i = 1; i <= n; i++) {
		ys += v[i] * (n - i + 1);
		bit.add(i, v[i]);
	}
	ll nb = LLONG_MIN;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ll pre = bit.query(i - 1);
		ll cur = ys - pre - v[i] * (n - i + 1);
		if (cur > nb) {
			nb = cur;
			ans = i;
		}
	}
	cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
}
