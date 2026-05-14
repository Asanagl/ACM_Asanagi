#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define ld long double 
#define pb push_back
struct node 
{
    int du = 0 ;
    vector <int> son_idx ;
} ;

int main ()
{
    int n ;
    cin >> n ;
    vector <node> pt (n+1) ;
    for (int i = 1 ; i <= n ; i++)
    {
        int m = 1 ; cin >> m ;
        while (m!=0)
        {
            pt[m].du++;
            pt[i].son_idx.pb(m) ;
            cin >> m ;
        }
    }
    queue <int> qe ;
    for (int i = 1 ; i <= n ; i++)
    {
        if (pt[i].du==0) qe.push(i);
    }
    vector <int> ans ;
    
    while (!qe.empty())
    {
        int idx ;
        idx = qe.front();
        qe.pop ();
        ans.pb(idx) ;
        for (auto &it : pt[idx].son_idx)
        {
            pt[it].du-- ;
            if (pt[it].du == 0) qe.push(it) ;
        }
    }
    for (auto &it : ans) cout << it << " " ;
}