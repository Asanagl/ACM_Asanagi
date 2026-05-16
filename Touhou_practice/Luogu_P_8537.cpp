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
    int n ;
    cin >> n ;
    vector <int> a (n) ;
    for (auto &it : a) cin >> it ;
    vector <int> tar (n) ;
    for (auto &it : tar) cin >> it ;
    vector <int> ar = a ;
    reverse (ar.begin(), ar.end()) ;
    int r = 0 , rr = 1 ;  
    for (int i = 0 ; i < n ; i++)
    {
        if (ar[i]!=tar[i]) rr++ ;
        if (a[i]!=tar[i]) r++ ;
    }
    cout << min (r , rr) << endl  ;
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