#include <bits/stdc++.h>
using namespace std ;
const int N=10100;
int dist[N];int n,m,s;
vector<pair<int,int>> v[N];
bool vis[N];
int main ()
{    
    
    cin >>n>>m>>s;
    for(int i=1;i<=n;i++){
        dist[i]=(1<<31)-1;
    }
    dist[s]=0;
    while(m--){
        int u,x,a;
        cin >>u>>x>>a;
        v[u].push_back({x,a});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
    while(!q.empty()){
        auto [l,r]=q.top();//取出当前距离源点最近点
        q.pop();
        if(vis[r])  continue;//如果当前点最短距离已经被确定，那么跳过
        vis[r]=1;//标记这个点的最短距离已经被确定
        for(auto [a,b]:v[r]){//遍历r的所有出边
            if(dist[a]>dist[r]+b){
                dist[a]=dist[r]+b;
                q.push({dist[a],a});//如果这个点最短距离被更新，那么将这个点加入队列中
            }
        }
    }
    for(int i=1;i<=n;i++)
    cout <<dist[i]<<" ";
}