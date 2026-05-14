#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    string s;
    int m;
    cin >> s >> m;
    int n = s.length();
    int x = 0, y = 0;
    int dx = 0, dy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'E') dx++;
        else if (s[i] == 'W') dx--;
        else if (s[i] == 'N') dy++;
        else if (s[i] == 'S') dy--;
    }
    
    int temp = m / n;
    int full = m % n;
    x += temp * dx;
    y += temp * dy;
    for (int i = 0; i < full; i++) {
        if (s[i] == 'E') x++;
        else if (s[i] == 'W') x--;
        else if (s[i] == 'N') y++;
        else if (s[i] == 'S') y--;
    }
    
    cout << x << " " << y << endl;


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