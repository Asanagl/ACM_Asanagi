#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void Asanagi()
{
    int n;
    cin >> n;
    map<int, bool> mp;
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (!mp.count(x))
        {
            mp[x] = true;
            res.push_back(x);
        }
    }
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    IOS ;
    int T;
    cin >> T;
    while (T--) Asanagi();
    return 0;
}