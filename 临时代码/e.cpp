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

void Asanagi()
{
    string p;
    cin >> p;
    int n;
    cin >> n;
    vector<string> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    bool targer = false;
    for (int i = 0; i < n; i++) {
        if (w[i] == p) targer = true;
    }
    bool st = false, nd = false;
    for (int i = 0; i < n; i++) {
        if (w[i][1] == p[0]) st = true;
        if (w[i][0] == p[1]) nd = true;
    }
    if (st && nd) targer = true;
    cout << (targer ? "YES" : "NO") << endl;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}