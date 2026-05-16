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


bool cmp (int a, int b)
{
    if (a %2 == 0 && b %2 != 0) return false;
    if (a %2 != 0 && b %2 == 0) return true;
    if (a %2 ==0 && b %2 ==0) return a < b;
    return a > b;
}
void Asanagi()
{
    vector<int> a(10);
    for (auto &it : a) cin >> it;
    sort(a.begin(), a.end() , cmp);
    for (auto it : a) cout << it << " ";
}

signed main()
{
    IOS;
    int t =1;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}