#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    int n ;
    cin >> n ;
    vector<ld> a(n) ;
    for (auto &i : a) cin >> i;
    while (a.size() > 1) {
        sort(a.begin(), a.end());
        ld x = a[0];
        ld y = a[1];
        ld z = sqrt(x * y);
        a.erase(a.begin(), a.begin() + 2);
        a.push_back(z);
    }
    cout << fixed << setprecision(10) << a[0] << endl;
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