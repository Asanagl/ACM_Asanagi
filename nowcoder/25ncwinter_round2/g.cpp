#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    vector<int> v(3);
    for (auto &i: v) cin >> i;
    sort (v.begin(), v.end());
    if (v[0]==0) {cout << "NO" << endl; return;}
    if (v[2]  > v[0] + v[1]) cout << "NO" << endl ;
    else cout << "YES" << endl;

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