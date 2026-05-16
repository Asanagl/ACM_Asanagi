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
    int n ;
    cin >> n ;
    int c[3] = { 0, 0 , 0} ; 
    for (int i = 0 ; i < n ; i++)
    {
        int x ;
        cin >> x ;
        c[x]++ ; 
    }
    int ans  = c[0] ;
    int maxn = 0 ;
    int ysnb = min (c[1] , c[2]) ;
    for (int i = 0 ; i <= ysnb ; i ++)
    {
        int temp  = i + (c[1] - i) / 3 + (c[2] - i) /3 ;
        maxn = max (maxn , temp) ;
    }
    cout << ans + maxn << endl ; 
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