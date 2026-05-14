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
const int inf = 1e5 + 10 ;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
string s, s1 ;
int ysnb [inf] ;
void solve()
{
    int n , p ;
    cin >> n >> p ;
    cin >> s ;
    s1 = s ;
    reverse(s1.begin(),s1.end()) ;
    if (s1 == s) 
    {
        cout << 0 << endl ;
        return ;
    }
    s = ' ' + s ;
    int sum = 0 , fs = 0 , ls = 0 ;
    for (int i = 1 ; i <= n/2 ; i++)
    {
        int minn = min (s[i] , s[n-i+1]) , maxn = max (s[i], s[n-i+1]) ;
        ysnb[i] = min (maxn - minn , minn + 26 - maxn) ;
        if (ysnb[i]!=0) { // 原神真牛逼
            ls = max(ls , i );
            if (fs == 0) fs = i ;
        }
        sum += ysnb[i] ;
    }
    if( p >= (n+1)/2+1 )  p = n - p + 1 ; 
    int ans = sum + min(abs(ls - p), abs(p - fs)) + ls - fs ;
    cout << ans << endl ;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}