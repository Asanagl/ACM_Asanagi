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


void exgcd(i128 a, i128 b, i128 &x, i128 &y) {
    if (b == 0) {
        x = 1; y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

i128 floord(i128 n, i128 d) {
    if (n >= 0) return n / d;
    else return (n - (d - 1)) / d;
}

i128 ceild(i128 n, i128 d) {
    if (n >= 0) return (n + d - 1) / d;
    else return n / d;
}

void Asanagi()
{
    ll xin, ain, bin;
    cin >> xin >> ain >> bin;
    i128 x = xin, a = ain, b = bin;
    i128 d = __gcd(a, b);
    if (x % d != 0)
    {
        cout << "No" << endl;
        return;
    }
    i128 a1 = a / d;
    i128 b1 = b / d;
    i128 x1 = x / d;
    i128 u, v;


    exgcd(a1, b1, u, v);
    i128 c10 = u * x1;
    i128 c20 = v * x1;
    i128 kl = ceild(-c10, b1);
    i128 kh = floord(c20, a1);


    if (kl > kh)
    {
        cout << "No" << endl;
        return ;
    }
    i128 L = kl, R = kh;
    i128 tosumval = c20 - c10;
    i128 sum = a1 + b1;
    i128 k1 = floord(tosumval, sum);
    i128 k2 = ceild(tosumval, sum);
    vector<i128> remu = {L, R};
    if (k1 >= L && k1 <= R)
        remu.push_back(k1);
    if (k2 >= L && k2 <= R && k2 != k1)
        remu.push_back(k2);
    i128 ansk = L;
    i128 ansc1 = c10 + ansk * b1;
    i128 ansc2 = c20 - ansk * a1;
    i128 ans = max(ansc1, ansc2);
    for (i128 k : remu)
    {
        i128 c1 = c10 + k * b1;
        i128 c2 = c20 - k * a1;
        i128 m = max(c1, c2);
        if (m < ans)
        {
            ans = m;
            ansk = k;
            ansc1 = c1;
            ansc2 = c2;
        }
    }
    cout << "Yes" << endl;
    cout << (ll)ansc1 << " " << (ll)ansc2 << endl;
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