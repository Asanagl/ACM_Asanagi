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

unordered_map<int ,int> fa , siz ,ha ;
set<int>st ;


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
    vector<PII> v ;
    fa.clear(); siz.clear(); ha.clear(); st.clear();
    int n ;
    cin >> n ;
    vector<int> x(n+1), y(n+1), e(n+1);

    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> x[i] >> y[i] >> e[i];
        st.insert(x[i]);
        st.insert(y[i]);
    }

    int idx = 0 ;
    for (auto &it : st)
        ha[it] = ++idx ;
    for (int i = 1 ; i <= idx ; i ++)
    {
        fa[i] = i;
        siz[i] = 1;
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        if (e[i] == 1)
            merge(ha[x[i]], ha[y[i]]);
        else
            v.push_back({ha[x[i]], ha[y[i]]});
    }
    int flag = 0 ;
    for (auto &it : v)
    {
        if (find(it.first) == find(it.second))
        {
            flag = 1 ;
            break ;
        }
    }
    cout << (flag ? "NO" : "YES") << endl ;
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
