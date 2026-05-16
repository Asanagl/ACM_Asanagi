#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n;
    int C;
    cin >> n >> C;
    vector<int> a(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++freq[a[i]];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long long target = a[i] + C;
        auto it = freq.find(target);
        if (it != freq.end()) {
            ans += it->second;
        }
    }

    cout << ans << endl;
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}