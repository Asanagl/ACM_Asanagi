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

void solve()
{
    vector<vector<int>> v(3, vector<int>(3));
    set<int> s;
    bool tri = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> v[i][j];
            if (v[i][j] < 1 || v[i][j] > 9 || s.count(v[i][j])) {
                tri = false;
            }
            s.insert(v[i][j]);
        }
    }

    if (s.size() != 9) tri = false;
    if (!tri) {
        cout << "No" << endl;
        return ;
    }
    int target = v[0][0] + v[0][1] + v[0][2];
    for (int i = 1; i < 3; ++i) {
        if (v[i][0] + v[i][1] + v[i][2] != target) {
            cout << "No" << endl;
            return ;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (v[0][j] + v[1][j] + v[2][j] != target) {
            cout << "No" << endl;
            return ;
        }
    }
    if (v[0][0] + v[1][1] + v[2][2] != target) {
        cout << "No" << endl;
        return ;
    }
    if (v[0][2] + v[1][1] + v[2][0] != target) {
        cout << "No" << endl;
        return ;
    }
    cout << "Yes" << endl;

}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}