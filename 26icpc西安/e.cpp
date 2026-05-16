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


void Asanagi()
{
    int n , x ;
    cin >> n >> x ;
    map<int , int> m ;
    set <int> st ;
    for (int i = 0 ; i < n ; i ++)
    {
        int c ;
        cin >> c ;
        st.insert(c) ;
        m[c]++ ;
    }
    int ans = 0 ;
    for (auto &it : st)
    {
        if (m[it] <= x) ans += m[it] ;
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