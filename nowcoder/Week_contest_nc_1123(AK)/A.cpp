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

void Asanagi()
{
    int x, y, p1, p2;
    cin >> x >> y >> p1 >> p2;
    if (x > y)
    {
        cout << "A" ;
    }
    else if (x < y)
    {
        cout << "B" ;
    }
    else if (x == y)
    {
        if (p1 < p2)
        {
            cout << "A" ;
        }
        else if (p1 > p2)
        {
            cout << "B" ;
        }
        else
        {
            cout << "C" ;
        }
    }
}

signed main() {
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) {
        Asanagi();
    }
    
    return 0;
}