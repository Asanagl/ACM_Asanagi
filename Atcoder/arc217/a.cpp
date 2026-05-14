#include <bits/stdc++.h>
using namespace std ;
#define int long long
void Asanagi ()
{
    int n;
    cin >> n;
    vector<int> ans;
    if (n == 2)
        ans = {1, 2};
    else if (n % 4 == 0)
    {
        for (int i = 1; i <= n; i += 4)
        {
            ans.push_back(i + 1);
            ans.push_back(i + 2);
            ans.push_back(i);
            ans.push_back(i + 3);
        }
    }
    else if (n % 4 == 1)
    {
        ans.push_back(1);
        for (int i = 2; i <= n; i += 4)
        {
            if (i + 1 <= n)
                ans.push_back(i + 1);
            if (i + 2 <= n)
                ans.push_back(i + 2);
            if (i <= n)
                ans.push_back(i);
            if (i + 3 <= n)
                ans.push_back(i + 3);
        }
    }
    else if (n % 4 == 2)
    {
        ans.push_back(1);
        ans.push_back(3);
        for (int i = 4; i <= n; i += 4)
        {
            if (i + 1 <= n)
                ans.push_back(i + 1);
            if (i + 2 <= n)
                ans.push_back(i + 2);
            if (i <= n)
                ans.push_back(i);
            if (i + 3 <= n)
                ans.push_back(i + 3);
        }
    }
    else if (n % 4 == 3)
    {
        ans.push_back(2);
        ans.push_back(3);
        ans.push_back(1);
        for (int i = 4; i <= n; i += 4)
        {
            if (i + 1 <= n)
                ans.push_back(i + 1);
            if (i + 2 <= n)
                ans.push_back(i + 2);
            if (i <= n)
                ans.push_back(i);
            if (i + 3 <= n)
                ans.push_back(i + 3);
        }
    }
    for (size_t i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
signed main ()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        Asanagi();
    }
}