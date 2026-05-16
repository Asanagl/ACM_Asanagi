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

vector<int> cirno = {9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999,99999999999,999999999999,9999999999999,9999999999999,99999999999999,999999999999999,9999999999999999}; ;
void Asanagi()
{
    int ans = LLONG_MAX;
    int x ;
    cin >> x ;
    for (int y : cirno)
    {
            if (y < x) continue;
            if ((y - x) % 9 == 0)
            {
                ans = min(ans, (y - x) / 9);
            }
            int A = y / 9 - x;
            if (A >= 0)
            {
                int temp = A / 9;
                int steps = A + 1 - 8 * temp;
                ans = min(ans, steps);
            }
    }
    cout << ans << endl;
    }



signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}





