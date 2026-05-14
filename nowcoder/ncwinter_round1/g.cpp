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
const int MAXE = 19;

vector<ll> powx(MAXE + 1);

void init()
{
    powx[0] = 1;
    for (int i = 1; i <= MAXE; ++i)
    {
        powx[i] = powx[i - 1] * 10;
    }
}

int digits(ll x)
{
    int d = 0;
    while (x > 0)
    {
        x /= 10;
        ++d;
    }
    return d;
}

ll floor_comp(ll a, ll b)
{
    if (b < 0)
        a = -a, b = -b;
    if (a >= 0)
        return a / b;
    else
        return (a - b + 1) / b;
}

ll ceil_comp(ll a, ll b)
{
    if (b < 0)
        a = -a, b = -b;
    if (a > 0)
        return (a + b - 1) / b;
    else
        return a / b;
}

ll changemax_rev(ll L, ll R, int D)
{
    if (L > R)
        return -1;
    if (D == 1)
    {
        for (int d = 9; d >= 1; --d)
        {
            if (L <= d && d <= R)
                return d;
        }
        return -1;
    }
    ll j = 0;
    ll suf = 0;
    for (int i = 0; i < D; ++i)
    {
        int start = (i == 0 ? 9 : 9);
        bool trigger = false;
        for (int d = start; d >= (i == 0 ? 1 : 0); --d)
        {
            ll nsuf = suf + d * powx[i];
            int sufl = i + 1;
            if (D - sufl > 0)
            {
                ll hlower = powx[D - sufl - 1];
                ll hupper = powx[D - sufl] - 1;
                if (R < nsuf)
                    continue;
                ll rltemp = ceil_comp(L - nsuf, powx[sufl]);
                ll rhtemp = floor_comp(R - nsuf, powx[sufl]);
                ll low = max(hlower, rltemp);
                ll high = min(hupper, rhtemp);
                if (low <= high)
                {
                    trigger = true;
                }
            }
            else
            {
                if (nsuf >= L && nsuf <= R)
                {
                    trigger = true;
                }
            }
            if (trigger)
            {
                j = j * 10 + d;
                suf = nsuf;
                break;
            }
        }
        if (!trigger)
            return -1;
    }
    return j;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    int max_len = digits(r);
    ll ans = -1;
    for (int D = max_len; D >= 1; --D)
    {
        int el = MAXE + 1, eh = -1;
        for (int e = 0; e <= MAXE; ++e)
        {
            if (powx[e] > r)
                break;
            ll A = (l + powx[e] - 1) / powx[e];
            ll B = r / powx[e];
            if (A > B)
                continue;
            if (B < powx[D - 1] || A > powx[D] - 1)
                continue;
            if (A <= powx[D] - 1 && B >= powx[D - 1])
            {
                el = min(el, e);
                eh = max(eh, e);
            }
        }
        if (el > eh)
            continue;
        ll L = max(powx[D - 1], (l + powx[eh] - 1) / powx[eh]);
        ll R = min(powx[D] - 1, r / powx[el]);
        if (L > R)
            continue;
        ll cur = changemax_rev(L, R, D);
        if (cur != -1)
        {
            ans = cur;
            break;
        }
    }
    cout << ans << endl;
}

signed main()
{
    IOS;
    init();
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}