#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
const int N = 5000;
int n;
int l[N + 10], r[N + 10], u[N + 10], v[N + 10];
bool check(int m) {
	int j = 1;
	for (int i = 1; i <= n && j <= m; ++i) {
		int x = m - j + 1;
		if ((j < l[i] || j > r[i]) && (x < u[i] || x > v[i])) ++j;
	}
	return j == m + 1;
}

void Asanagi() 
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> u[i] >> v[i] ;
	for (int m = n; m >= 1; m--) {
		if (!check(m)) continue;
		cout << m << endl;
		return;
	}

	cout << 0 << endl;
}


signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
