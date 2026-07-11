#include <bits/stdc++.h>
using namespace std ;

#define ld long double
#define PII pair<ld, ld>
const ld INF = 1e9 + 10 ; 
ld graph[110][110] ;
void solve ()
{
    int n, m;
    cin >> n  ;
    unordered_map <ld , PII> ump ;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
                graph[i][j] = 0.0;
            else
                graph[i][j] = INF;
        }
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        int x , y ;
        cin >> x >> y ;
        ump[i].first = x ,ump[i].second = y ;
    }
    cin >> m ;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v ;
        ld c = sqrt((ump[v].first-ump[u].first)*(ump[v].first-ump[u].first) + (ump[v].second-ump[u].second)*(ump[v].second-ump[u].second));
        graph[u][v] = min(graph[u][v], c);
        graph[v][u] = min(graph[v][u], c);
        // cout << u << " ->" << v << " value " << graph[u][v] << endl  ;
        // cout << v << " ->" << u << " value " << graph[v][u] << endl  ;
    }
    int s, t;
    cin >> s >> t;
    for (int k = 1; k < n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                // cout << i << " ->" << j << " value " << graph[i][j] << endl  ;
            }
        }
    }
        cout << fixed << setprecision(2) <<graph[s][t] << endl;
}
int main ()
{
    solve();
}