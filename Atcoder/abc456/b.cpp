#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
string n , t ;
void solve()
{
    int cnt[3][7] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            int val;
            cin >> val;
            cnt[i][val]++;
        }
    }
    ld ans = 0.0;
    for (int x = 4; x <= 6; ++x) {
        for (int y = 4; y <= 6; ++y) {
            for (int z = 4; z <= 6; ++z) {
                if (x != y && y != z && x != z) {
                    ans += (cnt[0][x] / 6.0) *
                            (cnt[1][y] / 6.0) *
                            (cnt[2][z] / 6.0);
                }
            }
        }
    }

    cout << fixed << setprecision(10) << ans << endl ;

    

}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


