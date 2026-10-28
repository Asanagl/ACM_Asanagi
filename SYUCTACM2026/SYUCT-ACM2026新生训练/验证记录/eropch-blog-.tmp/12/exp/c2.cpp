#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
 int n,m; if(!(cin>>n>>m)) return 0;
 stringstream ss; ss<<cin.rdbuf();
 vector<int> v; int t; while(ss>>t) v.push_back(t);
 int N=n*m;
 for(int i=0;i<n;i++){ for(int j=0;j<m;j++){ int pos=i*m+j; int x=0,y=0;
   int seen=0;
   for(size_t k=2;k<v.size();k++){ if(seen==pos) { x=v[k]; break; } ++seen; }
   seen=0;
   for(size_t k=2+N;k<v.size();k++){ if(seen==pos) { y=v[k]; break; } ++seen; }
   if(j) cout<<' '; cout<<x+y; } cout<<'\n'; }
}
