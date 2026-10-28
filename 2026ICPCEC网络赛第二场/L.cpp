#include <bits/stdc++.h>
using namespace std ;
#define PII pair<int ,int>
const int N = 1e5 + 10 ;
int dist[N] ;
bool st[N] ;
int n , m ;
vector <PII> g[N] ;

int djk ()
{
    memset(dist , 0x3f , sizeof dist) ;
    memset(st , false , sizeof st) ;
    priority_queue<PII , vector <PII> , greater<PII>> q ;
    dist[1] = 0 ;
    q.push({0 , 1}) ;
    while (!q.empty())
    {
        auto t = q.top() ;
        q.pop() ;
        int ver = t.second ;
        if(st[ver]) continue ;
        st[ver] = true ;
        for (auto i : g[ver])
        {
            if (dist[i.first] > dist[ver] + i.second)
            {
                dist[i.first] = dist[ver] + i.second ;
                q.push({dist[i.first] , i.first}) ;
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1 ;
    return dist[n] ;
}

int main ()
{
    int t  ;
    cin >>t ;
    while (t--)
    {
        int n ;
        cin >> n ;
        vector <int> v (n+1) ;
        for (int i = 1; i <= n ; i++) cin >> v[i] ;
        vector<vector<int>> g (n+2 , vector<int> (n+2)) ;
        for (int i = 1 ; i <= n ; i++) 
        {
            g[1][i] = v[i] ;
        }
        for (int i = 2 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n ; j++)
            {
                if ((j+1) > n) g[i][1] = g[i-1][j] ;
                else g[i][j+1] = g[i-1][j] ;
            }
        }
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n ; j++)
            {
                cout << g[i][j] << " " ;
            }cout << endl ;
        }
    }
}
