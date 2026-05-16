#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const int N=2e5+10;
int r[N];
int d[N];
int siz[N];
queue<int> qe;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        d[i] = siz[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        d[r[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
            qe.push(i);
    }
    int ans = 0;
    while (!qe.empty())
    {
        int p = qe.front();
        qe.pop();
        ans = max(ans, ++siz[p]);
        siz[r[p]] = max(siz[r[p]], siz[p]);
        if (!--d[r[p]])
        {
            qe.push(r[p]);
        }
    }
    cout << ans + 2 << endl ;
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
