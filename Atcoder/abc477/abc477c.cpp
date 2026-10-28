#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;


vector<int> z_function(const string& s) 
{
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
void Asanagi()
{
    int q;
    cin >> q;
    string s, t;
    cin >> s >> t;
    
    int n = s.length();
    int m = t.length();
    string U = t + "#" + s;
    vector<int> z = z_function(U);
    vector<int> match(n, 0);
    for (int i = 0; i < n; i++) {
        if (z[i + m + 1] >= m) {
            match[i] = 1;
        }
    }
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + match[i];
    }
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = L - 1;
        int r = R - 1;
        if (R - L + 1 < m) {
            cout << "No" << endl;
            continue;
        }
        int count = pref[r - m + 2] - pref[l];
        
        if (count > 0) {
            cout << "Yes" <<endl ;
        } else {
            cout << "No" << endl;
        }
    }
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
