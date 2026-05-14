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

void solve()
{
    vector<string> text;
    string b;
    int c = 0;
    
    while (getline(cin, b)) {
        text.push_back(b);
        c = max(c, (int)b.length());
    }
    
    int d = c + 2;
    int e = text.size() + 2;
    
    vector<string> ans(e, string(d, ' '));
    
    for (int i = 0; i < e; i++) {
        ans[i][0] = '*';
        ans[i][d - 1] = '*';
    }
    for (int i = 0; i < d; i++) {
        ans[0][i] = '*';
        ans[e - 1][i] = '*';
    }
    
    bool tri = true;
    
    for (int i = 0; i < text.size(); i++) {
        int k = i + 1;
        int l = text[i].length();
        int m = c - l;
        
        int n;
        if (m % 2 == 0) {
            n = m / 2;
        } else {
            if (tri) {
                n = m / 2;
            } else {
                n = m / 2 + 1;
            }
            tri = !tri;
        }
        
        for (int j = 0; j < l; j++) {
            ans[k][1 + n + j] = text[i][j];
        }
    }
    
    for (int i = 0; i < e; i++) {
        cout << ans[i] << endl;
    }

}

signed main()
{
    IOS;
    int t =1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}