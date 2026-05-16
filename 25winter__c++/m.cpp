#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    if (a[0] < a[n - 1]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main()
{
    IOS;
    int t ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}