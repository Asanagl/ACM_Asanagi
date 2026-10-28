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
    int n , k ;
    cin >> n >> k;
    if (n - k < 2) 
    {
        cout << -1 << endl ;
        return ; 
    }
    int val1 = (k + 1) / 2 ;
    int val0 = (k) / 2;
    for (int i = 0 ; i < val0 ; i++)
    cout << "0" ; cout << 0 ; 
    for (int i = 0 ; i < val1 ; i++)
    cout << "1" ; 
    
    for (int i = 0; i < n - val0 - val1 - 1;  i++)
    {
        if (i % 2 == 0) cout << 1 ;
        else cout << 0 ;
    }
    cout << endl ;
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
