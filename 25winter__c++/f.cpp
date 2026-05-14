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

void solve()
{
    string s ;
    cin >> s ;
    string ans = "yes" ;
    transform(s.begin(), s.end(), s.begin(), ::tolower) ;
    if (s == ans)
    {
        cout << "YES" << endl ;
    }
    else
    {
        cout << "NO" << endl ;
    }
}

signed main()
{
    IOS;
    int t ;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}