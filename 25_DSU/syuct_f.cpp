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
const int N = 100000005;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

unordered_map<int ,int> fa , siz ;
int find (int n)
{
    if(fa[n] == n) return n ;
    else return fa[n] = find(fa[n]) ; 
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (siz[x] > siz[y])
    {
        fa[y] = x;
        siz[x] += siz[y];
    }
    else
    {
        fa[x] = y;
        siz[y] += siz[x];
    }
}

void solve()
{
    fa.clear() , siz.clear() ;
    int n , m ;
    while(cin >> m ){
        fa.clear() , siz.clear() ;
    int ans = 1 ;
    set <int> st ;
    for (int i = 1 ; i <= m ; i++)
    {
        int x , y ;
        cin >> x >> y ;
        st.insert(x) , st.insert(y) ;
        if (fa[x] == 0)
        {
            fa[x] = x;
            siz[x] = 1 ;
        }
        if (fa[y] == 0)
        {
            fa[y] = y;
            siz[y] = 1 ;
        }
        merge(x ,y) ;
    }
    for (auto &it : st) 
    {
        ans = max (ans , siz[it]) ;
    }
    cout << ans << endl;
}
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
