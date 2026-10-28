#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define PII pair<int,int>
const int INF = 1e9+10;
const int LINF = 1e18+10;

void Asanagi()
{
    int n, d;
    cin >> n >> d; 
    vector<PII> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end(), [](PII a, PII b){ return a.first < b.first; });
    vector<int> ans;
    if (v[1].first - v[0].first >= d) ans.push_back(v[0].second);
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            if (v[i].first - v[i-1].first >= d) ans.push_back(v[i].second);
        } 
        else{
            if (v[i].first - v[i-1].first >= d && v[i+1].first - v[i].first >= d) 
                ans.push_back(v[i].second);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &it : ans) cout << it << " "; 
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
