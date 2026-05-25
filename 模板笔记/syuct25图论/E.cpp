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
struct node 
{
    int du = 0 ; 
    vector <int> son_idx ;
};
void Asanagi()
{
    int n , m ;
    while (cin >> n >> m)
    {
        vector <node> v (n+1) ;
        for (int i = 0 ; i < m ; i++)
        {
            int fi , se ;
            cin >> fi >> se ;
            v[se].du++ ;
            v[fi].son_idx.pb(se) ;
        }
        priority_queue<int , vector <int> , greater<int>> qe;
        for (int i = 1 ; i <= n ; i++ )
        {
            if (v[i].du==0) {
                qe.push(i) ; 
            }
        }
        vector <int> ans ;
        while (!qe.empty())
        {
            int idx ;
            idx = qe.top() ; 
            qe.pop() ;
            ans.pb(idx) ;
            for (auto &it : v[idx].son_idx)
            {
                v[it].du-- ;
                if (v[it].du == 0)
                qe.push(it) ; 
            }
        }
        for (auto &it : ans) cout << it << " " ;
        cout << endl ;
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
