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

void Asanagi()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = count(s.begin(), s.end(), '0');
    if (cnt == 0 || cnt == 1 && s.back() != '0') {
        cout << -1 << "\n";
    } else {
        vector<int> l = {1}, huan;
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == '1') {
                l.push_back(i + 2);
            } else {
                huan.push_back(i + 2);
            }
        }
        l.push_back(n);
        set<array<int, 2>> ans;
        for (int i = 0; i + 1 < l.size(); i++) {
            ans.insert({l[i], l[i + 1]});
        }
        for (int i = 0; i + 1 < huan.size(); i++) {
            ans.insert({huan[i], huan[i + 1]});
        }
        ans.insert({1, huan.front()});
        ans.insert({1, huan.back()});
        cout << ans.size() << endl;
        for (auto [u, v] : ans) {
            cout << u << " " << v << endl;
        }
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