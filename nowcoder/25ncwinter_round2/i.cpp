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
void Asanagi() {
    int n, m;
    cin >> n >> m;
    vector<string> vstr(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> vstr[i];
        for (auto c : vstr[i])
        {
            if (c == '0')
                cnt1++;
            else
                cnt2++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (vstr[i][j] == '0')
            {
                cout << (cnt1 > 1 ? 'Y' : 'N');
            }
            else
            {
                cout << (cnt2 > 1 ? 'Y' : 'N');
            }
        }
        cout << endl;
    }
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