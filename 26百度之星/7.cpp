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
const int INF = 2e9+10;
const int LINF = 2e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int n ;
    cin >> n ;
    vector <int> ans ; 
    int maxn = -INF ;
    int idx = 0 ; 
    int cnt = 0 ;
    map<int,int> mp ;
    for (int i = 0 ; i < n ; i++)
    {
        int it ;
        cin >> it ;
        mp[it]++ ;
        if (it == -1) 
        {
            ans.pb(i+1) ;
        } else {
            cnt += it ;
            maxn = max (maxn , it) ;
            if (maxn == it) idx = i + 1 ;
        }
    }
    if (n - cnt > maxn)
    {
        int nxt = n - cnt ;
        if ((nxt + ans.size() -1) / ans.size() < maxn && (idx != 0 && mp[maxn] == 1))
        {ans.pb(idx) ;
        sort (ans.begin() , ans.end()) ;}
        for (auto &it : ans)
        cout << it << " " ;
    } else 
    {
        cout << idx ;
    }
}


signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
