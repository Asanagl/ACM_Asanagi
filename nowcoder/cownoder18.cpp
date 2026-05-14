#include <bits/stdc++.h>
using namespace std ;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n);
    int zero_cnt = 0;
    vector<long long> b;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            zero_cnt++;
        }
        else
            b.push_back(abs(a[i]));
    }
    long long ans = 1LL * zero_cnt * (zero_cnt - 1) / 2;
    sort(b.begin(), b.end());
    int m = b.size();
    int j = 0;
    for (int i = 0; i < m; ++i)
    {
        if (j <= i)
        {
            j = i + 1;
        }
        while (j < m && b[j] <= 2 * b[i])
        {
            j++;
        }
        ans += (j - 1 - i);
    }

    cout << ans << endl;

    return 0;
}