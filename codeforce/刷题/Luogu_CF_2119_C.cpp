#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void solve()
{
    int n , l , r , k ;
    cin >> n >> l >> r >> k ;
    if (n==2) {
        cout << -1 << endl ;
        return ;
    }
    if (n % 2 ==1) 
    {
        cout << l << endl ;
        
        return ;
    }
    int L ;
	L = l ;
    int R = r;
    for (R = 2; R <= L; R *= 2);
    if (R > r)
    {
        cout << "-1" << endl;
        return;
    }
    if (k == n || k == n - 1)
        cout << R << endl;
    else
        cout << L << endl;
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}