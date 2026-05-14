#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
// #define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const int N = 1005;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void solve()
{
    int n , m;
    cin >> n >> m ;
    int ans = 0 ;
    int dp ;
    cin >> dp ;
    bool flag = false ;
    for (int i = 0 ; i < n ; i ++)
    {
        if (dp == -1) return ;
        if (flag )
        {
            cout << "! " << ans <<endl ; 
        }
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