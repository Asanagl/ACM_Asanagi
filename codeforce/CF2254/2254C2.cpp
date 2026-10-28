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
    string a , b ;
    int n  ;
    cin >> n ;
    cin >> a >> b ;
    int s1 = 0  , s2 = 0  , s3 = 0 , s4 = 0 ;
    for (int i = 0 ; i < n ; i += 2)
    {
       if ( a[i] == '1' ) s1++ ;
       if ( b[i] == '1' ) s3++ ;
    }
    for (int i = 1 ; i < n ; i += 2)
    {
       if ( a[i] == '1' ) s2++ ;
       if ( b[i] == '1' ) s4++ ;
    }
    bool tri ;
    if (s1 == s3 && s2 == s4)
    {
        tri = true ;
    } else tri = false ;
    vector <int> pos1 , pos2 , pos3 , pos4 ;
    if (tri) 
    {
        for (int i = 0; i < n; i += 2) 
        {
            if (a[i] == '1')    pos1.pb(i) ;
            if (b[i] == '1')    pos2.pb(i) ;
        }
        for (int i = 1; i < n; i += 2) 
        {
            if (a[i] == '1')    pos3.pb(i) ;
            if (b[i] == '1')    pos4.pb(i) ;
        }
        int ans = 0 ;
        for (int i = 0 ; i < pos1.size() ; i++)
        {
            ans += abs(pos1[i] - pos2[i]) ;
        }
        for (int i = 0 ; i < pos3.size() ; i++)
        {
            ans += abs(pos3[i] - pos4[i]) ;
        }
        cout << ans/2 << endl ;

    } else
        cout << -1 << endl;
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
