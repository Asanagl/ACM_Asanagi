#include <bits/stdc++.h>
using namespace std; //Izayoi——Sakuya

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;


const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int encode(int parity, int used, int ghost_parity, int freeze_left)
{
    if (used == 0)
        return parity;
    if (freeze_left == 0)
        return 2 + parity;
    if (freeze_left == 1)
        return 4 + 2 * parity + ghost_parity;
    return 8 + 2 * parity + ghost_parity;
}

void decode(int sub, int &parity, int &used, int &ghost_parity, int &time_left)
{
    if (sub < 2)
    {
        used = 0;
        parity = sub;
        ghost_parity = parity;
        time_left = 0;
    }
    else if (sub < 4)
    {
        used = 1;
        parity = sub - 2;
        ghost_parity = parity;
        time_left = 0;
    }
    else if (sub < 8)
    {
        used = 1;
        int base = sub - 4;
        parity = base / 2;
        ghost_parity = base % 2;
        time_left = 1;
    }
    else
    {
        used = 1;
        int base = sub - 8;
        parity = base / 2;
        ghost_parity = base % 2;
        time_left = 2;
    }
}

void Asanagi()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> ghost[2];
    ghost[0].assign(n, vector<bool>(m, false));
    ghost[1].assign(n, vector<bool>(m, false));

    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        ghost[1][x1][y1] = true;
        ghost[0][x2][y2] = true;
    }

    if (n == 1 && m == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    const int SUB = 12;
    int total = n * m * SUB;
    vector<int> dist(total, -1);

    auto idx = [&](int x, int y, int sub)
    {
        return (x * m + y) * SUB + sub;
    };

    deque<tuple<int, int, int>> dq;
    int start = encode(1, 0, 1, 0);
    dist[idx(0, 0, start)] = 0;
    dq.emplace_front(0, 0, start);

    while (!dq.empty())
    {
        auto [x, y, sub] = dq.front();
        dq.pop_front();
        int cur = idx(x, y, sub);
        int d = dist[cur];

        int parity, used, ghost_parity, freeze_left;
        decode(sub, parity, used, ghost_parity, freeze_left);

        if (used == 0)
        {
            int nsub = encode(parity, 1, parity, 2);
            int nxt = idx(x, y, nsub);
            if (dist[nxt] == -1)
            {
                dist[nxt] = d;
                dq.emplace_front(x, y, nsub);
            }
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            int nparity = 1 - parity;
            int nused = used;
            int nfreezze, nghost;
            if (freeze_left > 0)
            {
                nfreezze = freeze_left - 1;
                if (nfreezze > 0)
                    nghost = ghost_parity;
                else
                    nghost = nparity;
            }
            else
            {
                nfreezze = 0;
                nghost = nparity;
            }
            if (ghost[nghost][nx][ny])
                continue;
            int nsub = encode(nparity, nused, nghost, nfreezze);
            int next = idx(nx, ny, nsub);
            if (dist[next] == -1)
            {
                dist[next] = d + 1;
                if (nx == n - 1 && ny == m - 1)
                {
                    cout << d + 1 << endl;
                    return 0;
                }
                dq.emplace_back(nx, ny, nsub);
            }
        }
    }
    cout << -1 << endl;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
