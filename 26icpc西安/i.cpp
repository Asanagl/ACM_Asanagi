#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    priority_queue<ll> pq;
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
        pq.push(v[i]);
    }
    vector<ll> b(m), c(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
        cin >> c[i];
    vector<pair<ll, ll>> ysnb(m);
    for (int i = 0; i < m; i++)
        ysnb[i] = {c[i], b[i]};
    sort(ysnb.begin(), ysnb.end(), greater<pair<ll, ll>>());
    for (auto &[cval, bval] : ysnb)
    {
        if (pq.empty())
            break;
        ll v = pq.top();
        pq.pop();
        ll save = min(v, cval) - bval;
        if (save > 0)
        {
            total -= save;
            pq.push(bval);
        }
        else
        {
            pq.push(v);
        }
    }
    cout << total << endl;
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

