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
    vector <int> a (n+1) ;
    vector <int> b (n+1) ;
    for (int i = 1 ; i <= n ; i++)
    cin >> a[i] ;
    for (int i = 1 ; i <= n ; i++)
    cin >> b[i] ;
    for (int i = n ; i >= 2 ; i--)
    {
        if (a[i] <= b[i]) a[i] = b[i] ;
        else {a[i-1] += (a[i]-b[i]); a[i] = b[i];}
    }
    if (a[1]<=b[1]) cout << "YES" << endl ;
    else cout << "NO" << endl ;
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
