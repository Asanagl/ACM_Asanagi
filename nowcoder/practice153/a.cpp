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

void Asanagi()
{
    string s;
    cin >> s;
    int c2 = 0, c20 = 0, c202 = 0, mx = 0;
    int ans = 0, n = s.size();
    for (int i = 0; i < n; i++) 
    {
        if (s[i] == '2') 
        {
            c202 += c20;
            ++c2;
        } else if (s[i] == '0') 
        {
            c20 += c2;
        }
        if (c202 > mx) 
        {
            mx = c202;
            ans = i + 1;
        }
    }
    cout << ans << endl;
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
