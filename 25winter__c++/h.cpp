#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n , m ;
    cin >> n >> m ;
    vector <int> v (n) ;
    for (auto &it : v ) cin >> it ;
    int sum  = 0 ;
    for (auto &it : v ) sum += it ;
    if (sum <= m ) cout << sum << endl;
    else 
    // if((sum - m)>=m*(n-1)) 
    cout << m << endl;
}

signed main()
{
    IOS;
    int t  ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}