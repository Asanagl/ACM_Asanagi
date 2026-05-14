#include <bits/stdc++.h>
using namespace std ;
const int n  = 10 ;
vector <int> ans (n) ;
vector <bool> mark (n) ;
int n ;
void dfs(int u)
{
    if (u==n)
    {
        for (int i = 0 ; i < n ; i++)
        cout << ans[i] << " " ;
        puts("") ;
        return ;
    }
    for (int i =1 ; i <= n ; i++)
    {
        if (mark[i]==false)
        {
            mark[i] = true ;
            ans[u] = i ;
            dfs(u+1) ;
            mark[i] = false ;
            ans[u]=0 ;
        }
    }
}

int main ()
{
    int n , m ;
    cin >> n >> m ;
    vector <int>  v (n) ;
    // 先搓一个DFS

}