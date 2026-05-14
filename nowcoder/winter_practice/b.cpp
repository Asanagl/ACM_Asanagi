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
    cin  >> s ; 
    int n = s.size() ;
    if(n > 10)
    cout << s[0] << n-2 << s[n-1] << endl;
    else cout << s << endl;
}


signed main()
{
    IOS;
    int t  ;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}