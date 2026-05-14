#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

using ll = long long ;

void solve()
{
    int n ;
    cin >> n ;
    int ans = 0 ;
    cin >> ans ;
    int temp ;
	for(int i = 2 ; i <= n ; i++ ) {
		cin >> temp ;
		ans ^= temp;
	}
	cout << ans;
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}