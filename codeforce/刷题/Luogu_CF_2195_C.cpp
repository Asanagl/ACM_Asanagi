#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 3e5+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi ()
{
    int n ;
    cin >> n ;
    if (n==1)
    {
        int a ;
        cin >> a ;
        cout << 0 << endl ;
        return ;
    }
    else if (n==2)
    {
        int a , b ;
        cin >> a >> b ;
        if (a+b == 7 || a==b )
        cout << 1 << endl ;
        else  cout << 0 << endl ;
        return ;
    }
    vector <int> v (n+10) ;
    for (int i = 1; i <= n ; i++)
    cin >> v[i] ;
    int ans = 0 ;
    for (int i = 2 ; i <= n ; i++ )
    {
        if (v[i]==v[i-1]||(v[i-1]+v[i]==7))
        {
            ans++ ;
            i++ ;
        }
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