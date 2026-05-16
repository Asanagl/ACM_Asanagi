#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    if (n==1){cout << 1 << endl; return ;}
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] ;
    }
    for (int i = 0; i < n; i++) 
    if (a[i]==0) a[i]-- ;
    unordered_map < int , int > ump ;
    ump[0]=-1 ;
    int ans = 0 ;
    int prefix = 0 ;
    for (int i = 0; i < n; i++)
    {
        prefix += a[i] ;
        if (ump.find(prefix) != ump.end())
        {
            ans = max(ans , i - ump[prefix]) ;
        }
        else
        {
            ump[prefix] = i ;
        }
    }
    cout << ans << endl ;
        
}




signed main()
{
    IOS;
    int t = 1 ;
    // cin >> t;
    while (t--)
    {
            Asanagi();
    }
    return 0;
}