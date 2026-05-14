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
void solve()
{  
    int l , r ;
    cin >> l >> r ;
    bool fl;
    
    for (; l <= r ; l++)
    {
        fl = true ;
        map<char , int>mp;
        string str = to_string(l) ;
        for (auto &it : str) 
        {
            mp[it]++;
            if (mp[it]==2);
            {fl = false ;
            break;
            }
        }
        cout << l  ;
        cout << fl << " ";
        if (fl){
            cout << l;return;
        }
    }
    if (!fl) cout << -1 ;
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