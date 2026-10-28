#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
const int inf = 1e6 + 10 ;
struct node
{
    int minn = inf  , maxn = 0 , val = 0 ; 
}v[inf];
bool cmp(node a,node b){
    return a.minn<b.minn;
}
bool st[inf];
void solve()
{
    int n , m ;
    cin >> n >> m ;
    bool flag=0;
    for (int i = 0 ; i < m ; i ++)
    {
        int l , r ;
        cin >> l >> r ; 
        int len = r - l + 1 ;
        for (int j = 1 ; j <= len; j++)
        {
            int it ;
            cin >> it ;
            if (v[it].val == 0)
            {
                v[it].maxn = n-(len-j);
                v[it].minn = j ;
                v[it].val = it ;
            } else 
            {
                v[it].maxn=min(n-(len-j),v[it].maxn);
                v[it].minn=max(v[it].minn,j);
                if(v[it].maxn<v[it].minn){
                    flag=1;
                }
            }
            cout <<  it << ' '  << v[it].minn << ' ' << v[it].maxn << endl;
        }

    }
    if(flag==1){
        cout << -1 << endl;
        return;
    }
    sort(v+1,v+1+n,cmp);
    vector<int> ans(n+1);
    for(int d=1;d<=n;d++){
        int i=v[d].val;
        if(v[d].val==0){
            ans[i]=i;
            st[i]=true;
            continue;
        }
        int j=v[i].minn;
        while(st[j]&&j<=v[i].maxn) j++;
        ans[i]=j;
        st[j]=true;
    }
   for(int i=1;i<=n;i++){
    cout << ans[i] << ' ';
    st[i]=false;
   }
   cout << endl;
}
int main ()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
