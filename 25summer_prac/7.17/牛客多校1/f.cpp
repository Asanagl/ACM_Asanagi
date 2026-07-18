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
    int n, k , x; 
    cin >> n >> k >> x ; 
    vector <int> P (n) ;
    int pos = -1 ;
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> P[i] ;
        if (P[i] == x) pos = i ;
    }
    int d = (pos - k )% n ;
    if ( d < 0 ) d+=n ;
    vector <int> ans (n) ;
    for (int i = 0 ; i < n ; i++)
    {
        ans[i] = P[(i + d) % n]  ;
    }
    for (int i = 0 ; i < n ; i ++)
    {
        cout << ans[i] << " " ; 
    }
    cout << endl ;


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
