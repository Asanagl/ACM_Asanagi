#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int n , k ;
    string s, res;
    cin >> n >> k;
    vector<unordered_map<char, int>> mp(n + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            mp[i + 1][s[i]]++;
        }
    }
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    for (auto &it : v)
    {
        string ans;
        bool tri = true;
        for (int j = 1; j <= it; j++)
        {
            bool tri1 = false;
            for (char c = 'a'; c <= 'z'; c++)
            {
                bool tri2 = true;
                for (int k = j; k <= n; k += it)
                {
                    if (!mp[k].count(c))
                    {
                        tri2 = false;
                        break;
                    }
                }
                if (tri2)
                {
                    tri1 = true;
                    ans += c;
                    break;
                }
            }
            if (!tri1)
            {
                tri = false;
                break;
            }
        }
        if (tri)
        {
            int cnt = n / it;
            for (int i = 1; i <= cnt; i++)
            {
                cout << ans;
            }
            cout << endl;
            break;
        }
    }
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}