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

void Asanagi()
{
    int x0, n;
    cin >> x0 >> n;
    int d;
    switch (n % 4) {
        case 0: d = 0; break;
        case 1: d = n; break;
        case 2: d = -1; break;
        case 3: d = -n - 1; break;
    } 
    if (x0 % 2 == 0) {
        cout << x0 - d;
    } else {
        cout << x0 + d;
    }
    }


signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}