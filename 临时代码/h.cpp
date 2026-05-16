#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) //qian zhui he 
        {
            prefix[i] = prefix[i - 1] + (s[i - 1] == 'W' ? 1 : 0);
        }
        int minw = k;
        for (int i = 0; i <= n - k; i++) 
        {
            int sumw = prefix[i + k] - prefix[i];
            minw = min(minw, sumw);
        }
        cout << minw << endl;
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}