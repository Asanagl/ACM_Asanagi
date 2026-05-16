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

bool Binary_Search (int n , int x ,vector <int> &v)
{
    int r = n - 1 , l = 0 ;
    while (r >= l)
    {
        int mid = (l + r) / 2 ;
        if (v[mid] == x)
        {
            return true ;
        }
        else if (v[mid] > x)
        {
            r = mid - 1 ;
        }
        else
        {
            l = mid + 1 ;
        }
    }
    return false ;

}

void Asanagi()
{
    int n , t ;
    cin >> n >> t ;
    vector <int> v (n) ;
    for (auto &i : v) cin >> i ;
    sort (v.begin(),v.end());
    while (t--)
    {
        int x ;
        cin >> x ;
        int pos  = upper_bound(v.begin(),v.end(),x) - v.begin() ;
        if (v[pos]<=x || pos >= n ) cout << -1 << endl ;
        else 
        cout << v[pos] << endl ;
    }
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