#include <bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
const int INF = 1e9 + 10 ;void solve() 
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> v[i];
    }
    vector<int> lens;
    int cur = 1;
    for (int i = 1; i < n; i++) 
        if (v[i] != v[i - 1]) 
        {
            lens.push_back(cur);
            cur = 1;
        } 
        else cur++;
    lens.push_back(cur);
    sort(lens.begin(), lens.end());

    int m = (int)lens.size();
    int d = 0;

    int ans = 0;
    int i = 0;
    while(i < m)
    {
        int len = lens[i];
        int x = len - 1;
        int q = m - i;
        int curLen = n - d - x * q;
        if (curLen <= k && (k - curLen) % q == 0)
            ans++;
            
        int j = i;
        while (j < m && lens[j] == len)
            j++;
        d += (j - i) * lens[i];
        i = j;
    }

    cout << ans << endl;
}

signed main ()
{
    int t ;
    cin >> t;
    while (t--) solve();
}