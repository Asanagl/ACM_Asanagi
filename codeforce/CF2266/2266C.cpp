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
    string s ;
    cin >> s ;
   
    int ans = 0 ;
    for (int i = 0 ; i < n ; i++)
    { 
        ans += (s[i] == '0') ;  
    } 
    if (s[0] == '1')
    cout << ans << endl ;
    else 
    {
        int z = ans;
        ans = 1e9 ;
        int k = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            z -= (s[i] == '0') ;
            k += (s[i] == '1') ;
            ans = min (ans , k+z) ;
        }
        cout << ans << endl ;
    } 
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
