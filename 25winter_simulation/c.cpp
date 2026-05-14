#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    int n ;
    cin >> n ;
    bool found = false;
    for (int i = 0; i <= n / 7; i++) 
    {
        int temp = n - 7 * i;
        if (temp >= 0 && temp % 4 == 0) {
            int y = temp / 4;
            int z = n - i - y;
            cout << i << " " << y << " " << z << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No Answer." << endl;
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