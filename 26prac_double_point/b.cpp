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
    cin >> n;
    vector<int> v(n);
    for (int &e : v)
    {
        cin >> e;
    }
    int l = 0, r = n - 1;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            ans[i] = v[l++];
        }
        else
        {
            ans[i] = v[r--];
        }
    }
    for (auto i : ans)  cout << i << " ";
    cout << endl;
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}