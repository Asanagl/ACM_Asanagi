#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

// void init()
// {

// }

void solve()
{
    int n ;
    cin >> n ;
    vector <int> v{1 , 2 ,6 ,12 ,20 ,30 ,42 ,56 ,72 , 90}   ;
    if (find(v.begin(), v.end(), n) != v.end()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}