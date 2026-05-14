#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 5e5+10;
const int LINF = 1e18+10;
const int inf =  1e9+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

vector<int> prime;
int minp[INF];
array<array<int, 2>, 2> colori[INF];
void init()
{
    minp[1] = 1;
    for (int i = 2; i < INF; i++)
    {
        if (!minp[i])
        {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto &it : prime)
        {
            if (i * it >= INF)
                break;
            minp[i * it] = it;
            if (it == minp[i])
                break;
        }
    }
}

void solve()
{

    int n;
    cin >> n;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        while (w[i] > 1)
        {
            int x = minp[w[i]];
            while (w[i] % x == 0)
            {
                w[i] /= x;
            }
            temp.push_back(x);
        }
        int res = 1;
        for (auto &it : temp)
        {
            if (c[i] != colori[it][0][0])
            {
                res = max(res, colori[it][0][1] + 1);
            }
            if (c[i] != colori[it][1][0])
            {
                res = max(res, colori[it][1][1] + 1);
            }
        }
        for (auto &it : temp)
        {
            if (c[i] != colori[it][0][0])
            {
                if (res > colori[it][0][1])
                {
                    colori[it][1] = colori[it][0];
                    colori[it][0] = {c[i], res};
                }
                else if (res > colori[it][1][1])
                {
                    colori[it][1] = {c[i], res};
                }
            }
            else
            {
                if (res > colori[it][0][1])
                {
                    colori[it][0] = { c[i] , res } ;
                }
            }
            assert(colori[it][0][0] != colori[it][1][0]);
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}

signed main()
{
    IOS;
    init();
    int t = 1;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}




