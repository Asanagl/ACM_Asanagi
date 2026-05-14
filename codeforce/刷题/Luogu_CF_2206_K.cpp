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
int n, a[10];
bool check(int x, int y){
	int s0 = a[0], s1 = a[1], s01 = s0 + s1, s05 = s01 + a[2] + a[3] + a[4] + a[5], s09 = s05 + a[6] + a[7] + a[8] + a[9];
	s0 -= x;
	if(s0 < 0) return 0;
	s1 -= y;
	if(s1 < 0) return 0;
	s01 -= x + y; s05 -= x + y; s09 -= x + y;
	s01 -= y;
	if(s01 < 0)
		return 0;
	s05 -= y; s09 -= y;
	s05 -= x + y;
	if(s05 < 0)
		return 0;
	s09 -= x + y;
	s09 -= x * 2 + y;
	if(s09 < 0)
		return 0;
	return 1;
}
void Asanagi()
{
    for(int i = 0; i <= 9; ++ i)
			a[i] = 0;
		cin >> n;
		for(int i = 1; i <= n; ++ i){
			char c;
			cin >> c;
			++ a[c - '0'];
		}
		int ans = 0;
		for(int x = 0; x <= n; ++ x){
			int l = 0, r = n - x, res = -1e7;
			while(l <= r){
				int y = (l + r) >> 1;
				if(check(x, y))
					l = y + 1, res = y;
				else
					r = y - 1;
			}
			ans = max(ans, x + res);
		}
		cout << ans << endl;
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