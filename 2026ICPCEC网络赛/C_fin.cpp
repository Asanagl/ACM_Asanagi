
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define pb push_back
const int inf = 1e6 + 10;
#define IOS ios::sync_with_stdio(false) ; cin.tie(0); cout.tie(0)
struct node {
    int minn = 0, maxn = 0, val = 0;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<node> v(n + 2);
    bool flag = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        for (int j = 1; j <= len; j++) {
            int it;
            cin >> it;
            if (v[it].val == 0) {
                v[it].maxn = n - (len - j);
                v[it].minn = j;
                v[it].val = it;
            } else {
                v[it].maxn = min(n - (len - j), v[it].maxn);
                v[it].minn = max(v[it].minn, j);
                if (v[it].maxn < v[it].minn) {
                    flag = 1;
                }
            }
        }
    }
    if (flag == 1) {
        cout << -1 << endl;
        return;
    }
    
    int num = 1;
    int sum = 0;
    int maxx = 0;
    unordered_map<int, int> ump;
    for (int i = 1; i <= n; i++) {
        node it = v[i];
        // cout << it.maxn << " -- > " << it.minn << " val " << it.val << endl;
        if (it.val == 0) {
            sum++;
            cout << num << " ";
            ump[num]++ ;
            num++;
            maxx = max(maxx, num);
        } else {
            int i ; 
            for (i = it.minn + sum ; i <= it.maxn ; i++ )
            {
                if (ump[i] == 0 ){ cout << i << " " ; ump[i]++ ; break ;}

            }
            maxx = max(maxx, i);
            if (v[i + 1].val == 0) {
                sum = 0;
                num = maxx + 1;
            }
        }
    }
    cout << endl;
}
signed main() {
    IOS ;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
