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
    int  n ;
    cin >> n ;
    vector <int> a (n) ;
    vector <int> b (n) ;
    for (auto &it : a) cin >> it ;
    for (auto &it : b) cin >> it ;
    auto check = [&](int k) -> bool {
        int L = -2*INF , R = 2*INF ;
        for (int i = 0 ; i < n ; i++)
        {
            L = min (abs(a[i] - k * b[i]),a[i] + k * b[i])  ;
            R = max (abs(a[i] - k * b[i]),a[i] + k * b[i]) ;
            if (L > R ) return false ;
        }
        return L <= R ;
    } ;
    int lo = 0 , hi = 4 * INF , ans = hi ;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1 ;
        if (check(mid)){
            ans = mid ;
            hi = mid - 1 ;
        } else lo = mid + 1 ;
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
