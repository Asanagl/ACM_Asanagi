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

void solve()
{
    int n ;
    cin >> n ;
    vector <int> v (n+2) ; 
    for (int i = 1 ;i <= n ; i++)
    {
        cin >> v[i] ;
    }
    int sum = accumulate(v.begin() , v.end() ,0LL) ;
    if (sum % n != 0)
    {
        cout << -1 << endl ;
        return ;
    }
    ll x = sum / n;
    vector<ll> diff(n + 2);
    diff[1] = v[1] - x;
    for (int i = 2; i <= n; i++)
    {
        int ysnb = (i % 2 == 0) ? 1 : -1;
        diff[i] = ysnb * (2 * x - v[i - 1] - v[i]);
    }
    int mcnb = ((n + 1) % 2 == 0) ? 1 : -1;
    diff[n + 1] = mcnb * (x - v[n]);
    ll ans = 0;
    vector<ll> even, odd;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (diff[i] > 0)
            ans += diff[i];
        if (i % 2 == 0)
            even.push_back(diff[i]);
        else
            odd.push_back(diff[i]);
    }
    bool flag = true;
    ll prefix = 0;
    for (auto &it : even)
    {
        prefix += it;
        if (prefix < 0)
        {
            flag = false;
            break;
        }
    }
    if (prefix != 0)
        flag = false;
    if (flag)
    {
        prefix = 0;
        for (int i = (int)odd.size() - 1; i >= 0; --i)
        {
            prefix += odd[i];
            if (prefix < 0)
            {
                flag = false;
                break;
            }
        }
        if (prefix != 0)
            flag = false;
    }
    if (flag)
        cout << ans << endl;
    else
        cout << -1 << endl;
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}