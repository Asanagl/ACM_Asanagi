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
const int MOD =  998244353 ;
const int MAXN = 200005;
vector<int> fact(MAXN);

void init()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;
}
void Asanagi()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> ch;
    int ptr = 0;
    for (int j = 0; j < n; j++)
    {
        while (ptr < n && a[ptr] <= b[j])
            ptr++;
        if (ptr >= n)
            break;
        ch.push_back(n - ptr);
        ptr++;
    }

    int wins = ch.size();
    sort(ch.begin(), ch.end());

    int ans = 1;
    for (int i = 0; i < wins; i++)
    {
        ans = ans * (ch[i] - i) % MOD;
    }

    ans = ans * fact[n - wins] % MOD;
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
            Asanagi();
        }
    return 0;
}