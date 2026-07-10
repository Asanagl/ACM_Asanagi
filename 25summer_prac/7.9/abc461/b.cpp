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
    int n  ;
    cin >> n ;
    vector <int> a (n) ;
    vector <int> b (n) ;
    for (auto &it : a) cin >> it ;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> b[i] ;
        if (a[b[i]-1] != i+1 ) 
        {
            cout << "No" ;
            return ;
        }
    }
    cout << "Yes" ;
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
