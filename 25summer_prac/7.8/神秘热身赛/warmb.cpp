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
    int ans =0 ;
    int n ;
    cin >> n ;
    while (n--)
    {
        string s ;
        cin >> s ;
        if (s.size()!=5) continue ;
        if (s[2]!=s[4]) continue ;
        unordered_map <char,int> ump ;
        set<char> st ;
        int flag = false;
        for (int i = 0 ; i <= 3 ; i++)
        {
            ump[s[i]]++;
            if (ump[s[i]]!=1) {
                flag = true ;
                break;
            }
        }
        if (flag) continue ;
        else ans++;
    }
    cout << ans << endl ;
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
