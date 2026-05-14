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

void solve()
{
    int n , m ;
    cin >> n >> m ;
    vector <int> ori (n+1) ;
    vector <int> prefix (n+1) ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> ori[i] ;
        prefix[i] = ori[i] + prefix[i-1] ;
    }
    while (m--)
    {
        int l , r ;
        cin >> l >> r ;
        cout << prefix[r] - prefix[l-1] << endl ;
    }
    }

}

signed main()
{
    IOS;
    int t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}