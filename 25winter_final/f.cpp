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

void Asanagi()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ;
    vector <int> v1 (n) ;
    unordered_map <int , int> ump ;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i] ;
        v1[i] = v[i] - i + 1 ;
        ump [v1[i]]++ ;
    }
    int ans = 0 ;
    for (int i = 0 ; i < n ; ++i)
    {
        ump[v1[i]]-- ;
        if (ump[v1[i]] < 0) ump[v1[i]] =0 ;
        ans += ump [v1[i]] ;
    }
    cout << ans << endl;

}
// y = x - 9k +1

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}