#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
        }
        
        const ll INF = -1e12;
        ll ans[2] = {INF, INF};
        ll dp_pre = 0;  
        ll dp_cnt = 0;  
        for (int i = 0; i < n; ++i) {
            int p = abs(a[i]) % 2; 
            dp_cnt = dp_pre;
            if (ans[p] != INF) {
                dp_cnt = max(dp_cnt, ans[p] + a[i]);
            }
            ans[p] = max(ans[p], dp_pre + a[i]);
            dp_pre = dp_cnt;
        }
        cout << dp_cnt << endl;
    }
    return 0;
}