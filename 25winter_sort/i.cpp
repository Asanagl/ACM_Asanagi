#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

struct song 
{
    int ori ;
    int rar ;
    int cha ;
};

bool cmp (const song &a, const song &b)
{
    return a.cha > b.cha;
}

void solve()
{   
    int n ,dick ;
    cin >> n >> dick;
    vector<song> v(n);
    int total = 0 , total_rar = 0 ;
    for (auto &it : v) 
    {
        cin >> it.ori >> it.rar ;
        total += it.ori ;
        total_rar += it.rar ;
        it.cha = it.ori - it.rar ;
    }
    if (total_rar > dick) {cout << -1 << endl; return;}
    else if (total_rar == dick) {cout << n << endl; return;}
    else if (total <= dick) {cout << 0 << endl; return;}
    sort (v.begin() , v.end(),cmp) ;
    int ans = 0 , temp = total - dick ;
    for (auto it : v)
    {
        if (temp <= 0) break;
        if (it.cha <= temp)
        {
            temp -= it.cha ;
            ans++ ;
        }
        else
        {
            temp -= it.ori ;
            ans++ ;
        }
    }
    cout << ans << endl ;
}




signed main()
{
    IOS;
    int t =1;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}

