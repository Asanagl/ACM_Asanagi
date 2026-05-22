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

int ysnb (const vector <int> &v)
{
    int res = 0 , cur = 0 ;
    for (auto &it : v) 
    {
        cur = max (it , cur + it ) ; 
        res = max (res , cur ) ; 
    }
    return res ;
}
 
void Asanagi()
{
    int n ;
    cin >> n  ;
    vector <int> v (n) ;
    for (auto &it : v) cin >> it ;
    int num  = 0 ;
    for (auto &it : v) if (it & 1LL) num++ ;
    if (num > n / 2)
    {
        cout << "Alice" << endl ;
        return ;
    }
    vector <int> v1 , v2;
    for (int i = 0 ; i < n ; i ++)
    {
        int val = (v[i] & 1LL) ? -1 : 1 ;
        if (i & 1LL) v1.pb(val) ;
        else v2.pb(val) ;
    }
    int mcnb = max (ysnb(v1) , ysnb (v2)) ;
    cout << (num + mcnb > n / 2 ? "Alice" : "Bob") << endl; 
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
