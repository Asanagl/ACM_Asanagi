#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<int, int> first_oc;
    first_oc[0] = -1;

    int prefix_sum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        prefix_sum += (a[i] == 1 ? 1 : -1);

        if (first_oc.find(prefix_sum) != first_oc.end())
        {
            int len = i - first_oc[prefix_sum];
            max_len = max(max_len, len);
        }
        else
        {
            first_oc[prefix_sum] = i;
        }
    }

    cout << max_len << endl;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
