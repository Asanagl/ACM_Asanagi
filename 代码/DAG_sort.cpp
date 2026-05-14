#include <bits/stdc++.h>
using namespace std ;
struct node
{
    int du = 0 ;
    vector <int> son_idx ;
} ;
int main ()
{
    int n , m ;
    cin >> n >> m ;
    vector <node> pt(n+1) ;
    for (int i = 0 ; i < m ; i++)
    {
        int a , z  ;
        cin >> a >> z ;
        pt[a].son_idx.push_back(z) ;
        pt[z].du++;
    }

    queue <int> qe ;
    for (int i = 1 ; i <= n ; i++)
        if (pt[i].du == 0) qe.push(i) ;
    vector <int> ans ;

    while (!qe.empty())
    {
        int idx = qe.front();
        qe.pop();
        ans.push_back(idx) ;

        for (auto &it : pt[idx].son_idx)
        {
            pt[it].du-- ;
            if (pt[it].du == 0) qe.push(it) ;
        }
    }
    if (ans.size()!=n) cout << -1 ;
    else for (int i = 0 ; i < ans.size();i++)
    {
        if (i==ans.size()-1) cout << ans[i] ;
        else cout << ans[i] << " " ;
    }
}