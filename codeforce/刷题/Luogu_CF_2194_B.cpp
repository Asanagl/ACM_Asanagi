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

void Asanagi() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int sum = 0;
    for (int v : a) sum += (v / x) * y;
    
    int ans = 0;
    for (auto it : a) {
        int cur = it + sum - (it / x) * y;
        ans = max(ans, cur);
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