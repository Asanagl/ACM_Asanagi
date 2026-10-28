#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
const int inf = 1e6 + 10 ;
struct node 
{
    int minn = 0, maxn = 0, val = 0;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<node> v(n + 1);
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++) ans[i]=i;
    vector<int> temp(n+1);
    vector<int> num(n+1);
    bool flag = 0;
    for (int i = 0; i < m; i++) 
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        for (int j = 1; j <= len; j++) {
            int it;
            cin >> it;
            num[j]=it;
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
        if(flag==0){
            for(int i=1;i<=len;i++){
                temp[i]=ans[l+i-1];
            }
            for(int i=1;i<=len;i++){
                ans[num[i]]=temp[i];
            }
        }

    }
    if (flag == 1) {
        cout << -1 << endl;
        return;
    }
    for(int i=1;i<=n;i++) {
        // cout << v[i].maxn << "--> " << v[i].minn << endl ;    
        cout << ans[i] << " ";
    }
    cout << endl;
    
}
int main ()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
