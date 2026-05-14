#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    string str ;
    cin >> str ;
    unordered_map<char,int> mp ;
    for(auto i : str)
    {
        mp[i]++ ;
    }
    int ans = 0 ;
    if (str.size() <= 2 ||mp['1']==0 || mp['0']==0)
    cout << 0 << endl;
    else {ans = max (mp['1'],mp['0']) ;
        if (mp['1'] > mp['0'])cout << mp['0'] << endl;
        else if (mp['1'] < mp['0'])cout << mp['1'] << endl;
        
        else if (mp['1'] == mp['0']){ ans-- ;
        cout << ans << endl;}
    }

}

signed main()
{
    IOS;
    int t  ;
    // t = 1 ; 
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}