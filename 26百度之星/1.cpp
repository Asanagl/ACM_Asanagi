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
    int n , k , s;
    cin >> n >> k >> s ;
    vector <PII> v (n) ;
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> v[i].first >> v[i].second ;
    }
    sort (v.begin() , v.end() , [](PII a , PII b) {return a.first < b.first ;}) ;
    bool flag = false ;
    for (int i = 0 ; i < n ; i++)
    {
        while (s < v[i].first)
        {
            if (k == 0)
            {
                flag = true ;
                break ;
            }
            k-- ;
            s *= 2 ;
        }
        if (flag) break ;
        s += v[i].second ;
    }
    for (int i = 0 ; i < k ; i++)
    {
        s *= 2 ;
    }
    cout << s << endl;
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
