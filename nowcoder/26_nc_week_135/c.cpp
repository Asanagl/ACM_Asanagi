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
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    if (n == 1 || n >= 4)
    {
        cout << "YES" << endl;
    }
    else if (n == 2)
    {
        cout << (v[1] == 1 && v[2] == 2 ? "YES" : "NO") << endl;
    }
    else
    {
        if (v[2] == 2 && ((v[1] == 1 && v[3] == 3) || (v[1] == 3 && v[3] == 1)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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

