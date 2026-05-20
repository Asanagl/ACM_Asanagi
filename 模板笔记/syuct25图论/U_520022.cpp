#include<iostream>
#include<cstring>
using namespace std;
struct unt{
    int u,v,w;
};
const int N=505,M=10050;
unt edge[M];
int dist[N];
int dist2[N];
void songce(int m){//
    for(int i=0;i<m;i++){
        dist2[edge[i].v]=min(dist2[edge[i].v],dist[edge[i].u]+edge[i].w);
    }
    memcpy(dist,dist2,sizeof dist);
}
int main(){
    
}