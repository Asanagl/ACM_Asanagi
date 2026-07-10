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
    int n , q ;
    cin >> n >> q ;
    int len = 1 << n ;
    int u = q % len ;
    if (u % 2 == 0)
    cout << 0 << endl ;
    else cout << 1 << endl ;
    if (u % 2 == 0)
    {
        cout << (q / len) + u/2 << " ";
        for (int i = 2 ; i <= len-1 ; i++)
        cout << q / len << " ";
        cout << (q / len) + u/2 << endl;
    } else 
    {
        cout << (q / len) + u/2 << " ";
        for (int i = 2 ; i <= len-1 ; i++)
        {
            if (i = len/2) cout << (q/len) + 1 << " " ;
            else
            cout << q / len << " ";
        }
        
        cout << (q / len) + u/2 << endl;
    }
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
