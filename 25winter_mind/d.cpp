#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    int n;
	cin >> n;
	n /= 2;
	if (n & 1) 
    {
		cout << "NO" << endl;
		return  ;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) {
		cout << i * 2 << " ";
	}
	for (int i = 1; i < n; ++i) {
		cout << i * 2 - 1 << " ";
	}
	cout << 3 * n - 1 << endl;
}

signed main()
{
    IOS;
    int t  ;
    // t = 1 ; 
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}