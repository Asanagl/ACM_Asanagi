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
    int n , k ;
    cin >> n >> k ;
    string s ;
    cin >> s ;
    if  (n < 7 ) 
    {
        cout << 0 << endl ; 
        return ;
    }
    for (int i = 0 ; i < min(6LL , k) ; i++)
    {
        char ch = s[i] ;
        s.pb(ch) ; 
    }
    // cout << s << endl ;
    int ans = 0 ;
    for (int i = 0; i + 7 <= n + min(6LL , k); i++)
    {
        if (s.substr(i, 7) == "nanjing")
            ans++;
    }
    cout << ans << endl ;
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
