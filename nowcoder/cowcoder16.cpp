#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)
#define endl '\n'
#define ld long double
#define ll long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

ll pow10[20];

void init()
{
    pow10[0] = 1;
    for (int i = 1; i < 20; i++)
    {
        pow10[i] = pow10[i - 1] * 10;
    }
}

int digits(ll n)
{
    if (n == 0)
        return 1;
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

bool good(ll n)
{
    if (n < 1000)
        return false;
    int d = digits(n);
    ll prefix;
    if (d == 4)
    {
        prefix = n;
    }
    else
    {
        prefix = n / pow10[d - 4];
    }
    return (prefix >= 1005 && prefix <= 1010);
}

ll min_t(ll y, ll c)
{
    if (good(y))
        return 0;
    ll L, R;
    int m_cur;
    if (y < 1005)
    {
        L = 1005;
        R = 1010;
        m_cur = 4;
    }
    else
    {
        int m = max(4, digits(y));
        ll start = 1005 * pow10[m - 4];
        if (y < start)
        {
            L = start;
            R = 1011 * pow10[m - 4] - 1;
            m_cur = m;
        }
        else
        {
            L = 1005 * pow10[m - 3];
            R = 1011 * pow10[m - 3] - 1;
            m_cur = m + 1;
        }
    }
    while (true)
    {
        ll r = y % c;
        ll delta = (r - (L % c) + c) % c;
        ll g = L + delta;
        if (g <= R)
        {
            return (g - y) / c;
        }
        else
        {
            m_cur++;
            L = 1005 * pow10[m_cur - 4];
            R = 1011 * pow10[m_cur - 4] - 1;
        }
    }
}

int main()
{
    init();
    int T;
    cin >> T;
    while (T--)
    {
        ll x, a, b, c;
        cin >> x >> a >> b >> c;
        int d_x = digits(x);
        ll ans = 1e18;
        for (int k = 0; k <= d_x; k++)
        {
            ll y = x / pow10[k];
            ll t = min_t(y, c);
            ll cost = a * k + b * t;
            if (cost < ans)
            {
                ans = cost;
            }
        }
        cout << ans << endl;
    }
    return 0;
}