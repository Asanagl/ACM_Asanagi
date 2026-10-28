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
    cin >> s; 
    int n = s.size() ;
    int ans = 0 ;
    for (int i = 1 ; i < n ; i+=2)
    {
        if (s[i] == '1') s[i] = '0' ;
        else if (s[i] == '0') s[i] = '1' ;
    }
    for (int i = 0 ; i < n ; i ++)
    {
        if (s[i] == '1') ans++ ;
        if (s[i] == '0') ans-- ;
    }
    for (int i = 0 ; i < n ; i ++) 
    {
        if (s[i] == '2')
        {
            if (ans <= 0 ) ans++ ;
            else ans-- ;
        }
    }
    cout << abs(ans) << endl;
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
