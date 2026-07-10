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

int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

void Asanagi()
{
    string s ;
    cin >> s ;
    int ans = 0 ;
    for (int k = 0 ; k <= 25 ; k++)
    {
        string str = s ;
        int res = 0 ;
        for (auto &it : str)
        {
            it = (it-'A'+k)%26  ;
            res += holes_cnt[it] ;
        }
        ans = max (ans , res) ;
    }
    cout << ans ;

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
