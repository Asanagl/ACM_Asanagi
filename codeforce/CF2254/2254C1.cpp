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
    if (s1 == s3 && s2 == s4)
    {
        cout << "YES" << endl ;
    } else cout << "NO" << endl ;
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
