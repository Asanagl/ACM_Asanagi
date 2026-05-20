#include <bits/stdc++.h>
using namespace std ;
const int N=10100;
long long dist[N];int n,m,s;
vector<pair<int,int>> v[N];
bool vis[N];
void dijie(){
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&(t==-1||dist[j]<dist[t]))   t=j;
        }
        if(t==-1)   return;
        vis[t]=1;//t被加S集合里了
        for(auto [l,r]:v[t]){
            dist[l]=min(dist[l],dist[t]+r);
        }
    }
}
int main ()
{    
    
    cin >>n>>m>>s;
    for(int i=1;i<=n;i++){
        dist[i]=((long long)1<<31)-1;
    }
    dist[s]=0;
    while(m--){
        int u,x,a;
        cin >>u>>x>>a;
        v[u].push_back({x,a});
    }
    dijie();
    for(int i=1;i<=n;i++)
    cout <<dist[i]<<" ";
}