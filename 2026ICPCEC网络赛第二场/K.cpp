#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
int main() {
    #define int long long
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;bool z = false ;
        vector<int> v(n);
        unordered_map<int, int> ump;
        set<int> st;
        int mex = 0;
        for (int i = 0; i < n; i++) {
            int it;
            cin >> it;
            v[i] = it;
            ump[it]++;
            if (ump[it] == 2) z = true; 
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (mex == v[i])
                mex++;
        }
        
        int q;
        cin >> q;
        int ans = 0;
        int cnt_mex = 0;
        // cout << mex << endl ;
        while (q--) {
            unordered_map<int, int> mp;
            int k;
            cin >> k;
            if (k - mex < v[0] || k - mex > v[n-1] )
            {
                // cout << "!!" << k << endl ;
                ans ^= mex ;
                continue ;
            }
            cnt_mex = mex;
            while (1) {
                 if (ump[cnt_mex] - mp[cnt_mex] > 0) {
                    cnt_mex++;
                }else if ((k - cnt_mex < cnt_mex && ump[k - cnt_mex] >= 2) ) 
                {
                    mp[k - cnt_mex]++;
                    cnt_mex++;
                } 
                else if   ( (k - cnt_mex > cnt_mex && ump[k - cnt_mex] > 0)) {
                    mp[k - cnt_mex]++;
                    cnt_mex++;
                } else {
                    ans ^= cnt_mex;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}
