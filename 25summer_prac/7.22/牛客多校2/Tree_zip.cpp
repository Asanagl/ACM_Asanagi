#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long ;
int find(int x, vector<int> &dsu)
{
    int root = x;
    while (dsu[root] != root)
    {
        root = dsu[root];
    }

    while (dsu[x] != x)
    {
        int next = dsu[x];
        dsu[x] = root;
        x = next;
    }

    return root;
}

int main()
{
    int n, q;
    cin >> n >> q  ;
    for (int i = 2; i <= n; i++)
    {
        int fat ;
        cin >> fat ;
    }
    vector<vector<int>> fa_sec(n + 1);
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v ;
        fa_sec[v].pb(u);
    }
    vector<int> dsu(n + 1);
    vector<int> tresize(n + 1, 1);
    // nonefa[root] 表示这个并查集对应的新树片段中，最高且尚未确定父亲的节点。
    vector<int> nonefa(n + 1);
    // fa[x] 表示 x 在新树中的父亲。
    vector<int> fa(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dsu[i] = i;
        nonefa[i] = i;
    }

    // 原树祖先编号一定小于后代编号。
    // 倒序处理 v，相当于先处理更深的必经祖先。
    for (int v = n; v >= 2; v--)
    {
        for (int i = 0; i < fa_sec[v].size(); i++)
        {
            int u = fa_sec[v][i];
            int rootu = find(u, dsu);
            int rootv = find(v, dsu);
            // v 已经是 u 的祖先。
            if (rootu == rootv)
            {
                continue;
            }
            int ufafa = nonefa[rootu];
            int fafa = nonefa[rootv];
            // 为使 v 成为整个 u 片段的祖先，直接将片段最高点接到 v。
            // 插入任何额外节点只会增加片段内所有节点的深度。
            fa[ufafa] = v;
            if (tresize[rootu] < tresize[rootv])
            {
                dsu[rootu] = rootv;
                tresize[rootv] += tresize[rootu];
                nonefa[rootv] = fafa;
            }
            else
            {
                dsu[rootv] = rootu;
                tresize[rootu] += tresize[rootv];
                nonefa[rootu] = fafa;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (fa[i] == 0)
        {
            fa[i] = 1;
        }
    }
    vector<int> depth(n + 1, 0);
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        depth[i] = depth[fa[i]] + 1;
        ans += depth[i];
    }
    cout << ans ;
}