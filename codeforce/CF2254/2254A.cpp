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
    vector <int> v (3) ;
    for (auto &it : v) cin >> it ;
    sort (v.begin() , v.end()) ;
    if (v[0] == v[1] || v[1] == v[2]) 
    {
        cout << 0 << endl ;
        return ;
    }
    v[2]-- ; v[0]++ ;
    int ans = 1;
    while (1) {
        sort(v.begin(), v.end());
        if (v[0] == v[1] || v[1] == v[2]) {
            cout << ans << endl;
            return;
        }
        v[2]--;
        v[0]++;
        ans++ ;
    }
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
