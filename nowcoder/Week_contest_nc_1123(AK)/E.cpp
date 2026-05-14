#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    while (T--) 
    {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
        
        vector<pair<long long,long long>> p(n);
        for (int i = 0; i < n; ++i) p[i] = {a[i], b[i]};
        sort(p.begin(), p.end(),
             /**
              * 比较两个pair对象的第一个元素大小的lambda函数
              * 
              * @param x 第一个pair<long long, long long>类型的参数
              * @param y 第二个pair<long long, long long>类型的参数
              * @return 返回布尔值，当x的第一个元素小于y的第一个元素时返回true，否则返回false
              */
             [](const pair<long long,long long>& x,
                const pair<long long,long long>& y){ return x.first < y.first; });
        for (int i = 0; i < n; ++i) {
            a[i] = p[i].first;
            b[i] = p[i].second;
        }
        
        long long ans = 0;
        
        for (int i = 0; i < n; ++i)
            if (b[i] >= 3) ++ans;
        
        for (int i = 0; i < n; ++i) if (b[i] >= 2) {
            long long limit = 2 * a[i];
            int pos = lower_bound(a.begin(), a.end(), limit) - a.begin() - 1;
            if (pos >= 0) {
                int cnt = pos + 1;
                if (i <= pos) --cnt;
                ans += cnt;
            }
        }
        
        for (int k = 2; k < n; ++k) {
            int left = 0, right = k - 1;
            while (left < right) {
                if (a[left] + a[right] > a[k]) {
                    ans += (right - left);
                    --right;
                } else {
                    ++left;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}