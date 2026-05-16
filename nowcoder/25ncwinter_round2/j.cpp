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



struct city 
{
    int id;
    int degree;
};


void Asanagi()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> vvi(n + 1);
    vector<int> dvi(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
        dvi[a]++;
        dvi[b]++;
    }
    vector<int> ddvi;
    for (int i = 1; i <= n; ++i)
    {
        ddvi.push_back(dvi[i]);
    }
    sort(ddvi.begin(), ddvi.end());
    ddvi.erase(unique(ddvi.begin(), ddvi.end()), ddvi.end());
    int k = ddvi.size();
    vector<vector<int>> group(k);
    for (int i = 1; i <= n; ++i)
    {
        int ji = lower_bound(ddvi.begin(), ddvi.end(), dvi[i]) - ddvi.begin();
        group[ji].push_back(i);
    }
    vector<int> ans(n + 1, -1);
    vector<int> dist(n + 1, INF);
    queue<int> q;

    for (int i = k - 1; i > 0; --i)
    {
        for (auto it : group[i])
        {
            if (dist[it] != 0)
            {
                dist[it] = 0;
                q.push(it);
            }
        }
        // BFS
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : vvi[u])
            {
                if (dist[v] > dist[u] + 1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (auto it : group[i - 1])
        {
            if (dist[it] != INF)
            {
                ans[it] = dist[it];
            }
            else
            {
                ans[it] = -1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}