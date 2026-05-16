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
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n, q , s ;
    cin >> n >> q >> s;

    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        prefix[i] = prefix[i - 1] + t;
    }

    while (q--) 
    {
        int x, y;
        cin >> x >> y;
        cout << s + prefix[x - 1] + y - 1 << endl;
    }
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