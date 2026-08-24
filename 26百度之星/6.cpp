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
    int n ;
    cin >> n ;
    int cnt = 0 ;
    int op = 0 ;
    for (int i = 0 ; i < n ; i ++)
    {
        int a , b , c ;
        cin >> a >> b >> c ;
        if (c == 1)
        cnt ++ ;
        else op++ ;
    }
    if (n % 2 == 1 && (cnt == 0 || cnt == 1 || op == 1))
    cout << "First" << endl ;
    else cout << "Second" << endl ;
    // cout << cnt << " " << op << endl ;
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
