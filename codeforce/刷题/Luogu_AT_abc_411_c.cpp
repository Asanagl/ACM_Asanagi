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

void Asanagi()
{
    int n, q;
    cin >> n >> q;
    int ans = 0;
    vector<int> col(q + 2, 0);
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if (!col[x])
        {
            if (!col[x - 1] && !col[x + 1])
                ans++;
            else if (col[x - 1] && col[x + 1])
                ans--;
        }
        else
        {
            if (!col[x - 1] && !col[x + 1])
                ans--;
            else if (col[x - 1] && col[x + 1])
                ans++;
        }
        cout << ans << endl;
        col[x] = !col[x];
    }
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