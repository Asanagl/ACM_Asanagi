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
    string s;
    cin >> s ;
    // buhan ou
    bool ou = false ;
    int ouidx = 0 ;
    sort (s.begin(),s.end(),greater()) ;
    for (int i = 4 ; i >= 0 ; i--)
    {
        if (s[i]=='2'||s[i]=='6'||s[i]=='4'||s[i]=='8'||s[i]=='0'||s[i]=='5')
        {ou = true ;
        ouidx = i ;break;}
    }
    if (ou)
    {
        for (int i = 0 ; i < 5 ; i++)
    {
        if (i == ouidx) cout << s[4] ;
        else if (i==4) cout << s[ouidx] ;
        else
        cout << s[i] ;
    } cout << endl ;
    } else cout << s << endl;

    
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
