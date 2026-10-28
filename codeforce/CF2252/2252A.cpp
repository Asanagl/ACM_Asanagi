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
    int n ;
    cin >> n ;
    unordered_map <int ,int > ump ;
    int ans = 0 ;
    for (int i = 0 ; i < n ; i ++)
    {
        int it ;
        cin >> it ;
        ump[it]++ ;
        ans += it ;
    }
    for (auto &it : ump)
    {
        // cout << it.first << " " << it.second << endl ;
        if (it.second > n - it.second + 2)
        {
            ans -= (it.second -  (n - it.second + 2) ) * it.first;
        }
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
