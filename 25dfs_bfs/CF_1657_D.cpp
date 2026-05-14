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
struct sol 
{
    int c ;
    int d ;
    int h ;
    int val ;
};
struct mas
{
    int D ;
    int H ;
    int val ;
};
void solve()
{
    int n , m , C ;
    cin >> n >> C ;
    vector <sol> vs (n) ;
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> vs[i].c >> vs[i].d >> vs[i].h ;
        vs[i].val = vs[i].d * vs[i].h ;
    }
    cin >> m ;
    vector <mas> vm (m) ;
    for (int i = 0 ; i < m ; i++)
    {
        cin >> vm[i].D >> vm[i].H ;
        vm[i].val = vm[i].D * vm[i].H ;
    }
    vector <sol> best_s ;
    map<int , int> mp ;
    sort (vs.begin() , vs.end() , [](sol a , sol b){return a.val < b.val && a.c > b.c;});
    for (int i = 0 ; i < n ; i++)
    {
        if(mp[vs[i].val]==1) continue ;
        else mp[vs[i].val]++ ;
        best_s.pb(vs[i]);
    }
    vector<int> ans(m , -1) ;
    


}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}
