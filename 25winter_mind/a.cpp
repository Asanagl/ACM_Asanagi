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
    int a , b ;
    cin >> a >> b ;
    int temp = 7 - max (a ,b) ;
    if (temp == 1 || temp == 5) printf ("%d/6",temp) ;
    else if  (temp == 4 ) printf ("2/3") ;
    else {
        int temp2 = 6 / temp ;
        printf ("1/%d",temp2) ;
    }
}

signed main()
{
    IOS;
    int t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}