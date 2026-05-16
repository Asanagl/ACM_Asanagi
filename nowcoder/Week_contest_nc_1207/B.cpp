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

void Asanagi()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int fffffoooooodds = 0;
    for (int i = 0; i < n; i++) {
        if (fffffoooooodds + a[i] < x) {cout << "No" << endl;return;}
        fffffoooooodds = a[i] + min(fffffoooooodds, x) - x;
    }
    cout << "Yes" << endl;
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}