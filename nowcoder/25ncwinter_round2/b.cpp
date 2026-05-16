#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int maxn = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
        if (a[i] > maxn)
            maxn = a[i];
    }
    int temp = mp[maxn];
    string ans;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == maxn)
        {
            ans.push_back((temp % 2 == 1) ? '1' : '0');
        }
        else
        {
            ans.push_back((temp % 2 == 0) ? '1' : '0');
        }
    }
    cout << ans << endl;


}


signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}