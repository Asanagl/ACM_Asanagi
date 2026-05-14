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


void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    int fish[7] = {1, 0, 0, 1, 0, 1, 0};
    int rabbit[7] = {0, 1, 0, 0, 0, 1, 0};
    int chicken[7] = {0, 0, 1, 0, 1, 0, 1};
    for (int i = 0; i < 7; i++)
    {
        for (int l = 0; l < 7; l++)
        {
            int nfish = 0, nrabbit = 0, nchicken = 0;
            for (int j = 0; j < l; ++j)
            {
                int d = (i + j) % 7;
                nfish += fish[d];
                nrabbit += rabbit[d];
                nchicken += chicken[d];
            }
            if (nfish > a || nrabbit > b || nchicken > c)
                continue;
            int ansfish = (a - nfish) / 3;
            int ansrabbit = (b - nrabbit) / 3;
            int anschicken = (c - nchicken) / 3;
            int k = min({ansfish, anschicken, ansrabbit});
            int day = 7 * k + l;
            if (day > ans)
                ans = day;
        }
    }
    cout << ans;
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}