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
{ int n;
    cin >> n;
    
    vector<string> vs(n, string(n, '0'));
    
    if (n == 1) {
        cout << "0\n";
        return ;
    }
    if (n == 2) {
        cout << "01\n00"<<endl;
        return ;
    }
    vs[0][n-1] = '1';
    for (int i = 2; i < n; i++) {
        int cnt = i;
        int col = n - 1;
        while (cnt > 0 && col >= 0) {
            if (col != 1) {
                vs[i][col] = '1';
                cnt--;
            }
            col--;
        }
        col = n - 2;
        while (cnt > 0) {
            if (col != 1 && vs[i][col] == '0') {
                vs[i][col] = '1';
                cnt--;
            }
            col--;
            if (col < 0) col = n - 1;
        }
    }
    
    vs[n-1] = string(n, '1');
    vs[n-1][1] = '0';
    for (int i = 0; i < n; i++) {
        cout << vs[i] << endl;
    }
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}