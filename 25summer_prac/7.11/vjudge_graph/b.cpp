#include <bits/stdc++.h>
using namespace std ;
int graph[110][110] ;
const int INF = 1e9 + 10 ; 
void solve ()
{
    int n , m ;
    while (cin >> n >> m)
    {
        for (int i = 0 ; i <= n ; i++)
    {
        for (int j = 0 ; j <= n ; j++)
        {
            if (i == j) graph[i][j] = 0 ;
            else graph[i][j] = INF ;
        }
    }
        for (int i = 0 ; i < m ; i++)
        {
            int u , v , c ;
            cin >> u >> v >> c ;
            graph[u][v] = min (graph[u][v] , c ) ;
            graph[v][u] = min (graph[v][u] , c ) ;
            cout << u << " ->" << v << " value " << graph[u][v] << endl  ;
            cout << v << " ->" << u << " value " << graph[v][u] << endl  ;
        }
        int s , t ;
        cin >> s >>t ;
        for (int k = 0 ; k < n ; k++)
        {
            for (int i = 0 ; i < n ; i++)
            {
                for (int j = 0 ;j < n ;j++)
                {
                    graph[i][j] = min (graph[i][j] , graph[i][k] + graph[k][j]) ;
                }
            }
        }
        if (graph[s][t] == INF) cout << -1 << endl ;
        else cout << graph[s][t] << endl;
    } 
}
int main ()
{
    solve();
}