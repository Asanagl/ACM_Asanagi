#include <bits/stdc++.h>
using namespace std ;
int graph[110][110] ;
const int INF = 1e9 + 10 ; 
void solve ()
{
    int n , m ;
    while (cin >> n >> m)
    {
        if (n == m && n == 0) return ;
        for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
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
        }
        for (int k = 1 ; k <= n ; k++)
        {
            for (int i = 1 ; i <= n ; i++)
            {
                for (int j = 1 ;j <= n ;j++)
                {
                    graph[i][j] = min (graph[i][j] , graph[i][k] + graph[k][j]) ;
                }
            }
        }
        cout << graph[1][n] << endl ;
    } 
}
int main ()
{
    solve();
}