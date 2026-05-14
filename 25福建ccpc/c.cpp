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
const int inf = 1e5+10 ;

bool check(int x, const vector<int> &a)
{
    int cnt1 = 0;
    int cmp0 = 0;
    int len = 0;
    for (auto v : a)
    {
        if (v >= x)
        {
            cnt1++;
            if (len > 0)
            {
                if (len & 1)
                    cmp0 += 1;
                else
                    cmp0 += 2;
                    
                len = 0;
            }
        }
        else
        {
            len++;
        }
    }
    if (len > 0)
    {
        if (len & 1)
            cmp0 += 1;
        else
            cmp0 += 2;
    }
    return cnt1 > cmp0;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    if (n == 1)
    {
        cout << v[0] << endl;
        return;
    }
    vector<int> a = v;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int lo = 0, hi = a.size() - 1LL;
    while (lo < hi)
    {
        int mid = (lo + hi + 1LL) >> 1LL;
        if (check(a[mid], v))   lo = mid;
            else    hi = mid - 1;
    }
    cout << a[lo] << endl;
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}


