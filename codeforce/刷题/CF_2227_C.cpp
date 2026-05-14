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

void solve()
{
    int n;
    cin >> n;
    vector<int> a, b, c, d;
    for (int i = 0; i < n; i++)
    
    {
        int x;
        cin >> x;
        if (x % 6 == 0)
            a.push_back(x);
        else if (x % 2 == 0)
            b.push_back(x);
        else if (x % 3 == 0)
            c.push_back(x);
        else
            d.push_back(x);
    }
    vector<int> ans;
    for (auto it : a)
        ans.push_back(it);
    for (auto it : b)
        ans.push_back(it);
    for (auto it : d)
        ans.push_back(it);
    for (auto it : c)
        ans.push_back(it);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl ;
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}