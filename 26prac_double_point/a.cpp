#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    string str ;
    cin >> str ;
    string tar = "hello" ;
    int sum = 0 ;
    int j = 0 ;
    for (int i = 0 ; i < str.size() ; i++)
    {
        if (str[i]==tar[j]) 
        {
            j++;  sum++;
        }
    }
    if (sum==5) cout << "YES" ;
    else cout << "NO" ;
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}