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

void Asanagi()
{
    vector <int> v ;
    int n ;
    cin >> n ;
    int ans = 0 ;
    while (n--)
    {
        int type ;
        cin >> type ;
        if (type==1)
        {
            int l , r ;
            cin >> l >> r ;
            v.pb(l) ; v.pb(r) ; 
        }
        else 
        {
            int k ; 
            cin >> k ;
            bool tri = true ;
            while (tri)
            {
                int temp = k ;
                int r = v.back();
                v.pop_back();
                int l = v.back();
                v.pop_back();
                int len = r - l + 1 ;
                ans += (r + r - ( min (len,k) - 1 ) ) * min(len,k) / 2 ;
                k = k - min (len,k) ;
                if (k == 0 ) 
                {
                    if (temp <= len)
                    {
                        v.pb(l) ;
                        v.pb(r-temp) ;
                    }
                    break ;
                }
            }
            cout << ans << endl ;
            ans = 0 ;
        }
    }
    
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}