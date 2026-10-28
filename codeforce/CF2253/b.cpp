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

void Asanagi() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        if (b.empty() || b.back().first != a[i]) {
            b.emplace_back(a[i], 1);
        } else {
            b.back().second++;
        }
    }
    int m = b.size();
    for (int i = 0; i < m - 1; i++) {
        if (b[i].second > 1 && b[i + 1].second > 1) {
            cout << m + 2 << '\n';
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (i < m - 1 && b[i].second > 1 && (i + 2 >= m || b[i + 2].first != b[i].first)) {
            cout << m + 1 << '\n';
            return;
        }
        if (i > 0 && b[i].second > 1 && (i - 2 < 0 || b[i - 2].first != b[i].first)) {
            cout << m + 1 << '\n';
            return;
        }
    }
    cout << m << '\n';
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
