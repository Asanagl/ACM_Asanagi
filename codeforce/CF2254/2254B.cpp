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
    string s ;
    int n ;
    cin >> n >> s ;
    string s1 , s2 ;
    int ans = 1 , cur = 0 ;
    for (int i = 1 ; i < n ; i ++)
    {
        if (s[i]!=s[i-1]) ans++ ;
    }
    for (int i = 1 ; i < n-1 ; i++)
    {
        if (s[i] != s[i-1] && s[i] != s[i+1])
        {
            if (s[i-1] == s[i+1])
            {
                cur = max (cur , 2LL) ;
            } else cur = max(cur , 1LL) ;
        }
    }
    cout << ans - cur << endl ;
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
