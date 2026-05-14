#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void solve()
{
    int n ;
    cin >> n ;
    int ans = n ;
    vector <int> v (n+10);
    map <int ,int> mp ;
    int maxn = 0 ;
    for (int i = 0 ; i < n ; i++)
    {
        int it ;
        cin >> it ;
        mp[it] ++ ;
        maxn = max (maxn , mp[it]) ;
    }
    if (n==1)
    {
        cout << 1 << endl ;
        return ;
    }
    if (maxn <= n/2)
    {
        cout << n%2 << endl ;
        return ;
    }
    else 
    {
        cout << maxn - (n - maxn) << endl;
        return ;
    }

    
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}