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
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
int n , m ;
const int cskhyjnb[4] = {729, 81, 9, 1};
int change(int ysnb) 
{
    int d4 = ysnb % 10; ysnb /= 10;
    int d3 = ysnb % 10; ysnb /= 10;
    int d2 = ysnb % 10; ysnb /= 10;
    int d1 = ysnb;
    return (d1 - 1) * 729 + (d2 - 1) * 81 + (d3 - 1) * 9 + (d4 - 1);
}

void Asanagi()
{
    cin >> n >> m;
    int s = change(n);
    int e = change(m);
    int dist[6561];
    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == e)
            break;
        int d[4], tmp = u;
        for (int i = 0; i < 4; ++i)
        {
            d[i] = tmp / cskhyjnb[i];
            tmp %= cskhyjnb[i];
        }
        for (int i = 0; i < 4; ++i)
        {
            int ori = d[i];
            // +1
            d[i] = (ori + 1) % 9;
            int v = d[0] * 729 + d[1] * 81 + d[2] * 9 + d[3];
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            d[i] = (ori + 8) % 9;
            v = d[0] * 729 + d[1] * 81 + d[2] * 9 + d[3];
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            d[i] = ori;
        }
        for (int i = 0; i < 3; ++i)
        {
            swap(d[i], d[i + 1]);
            int v = d[0] * 729 + d[1] * 81 + d[2] * 9 + d[3];
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            swap(d[i], d[i + 1]);
        }
    }

    cout << dist[e] << endl;
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