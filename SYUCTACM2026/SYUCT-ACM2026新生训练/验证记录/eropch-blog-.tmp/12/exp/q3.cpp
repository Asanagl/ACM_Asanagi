#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
 int n,m; if(!(cin>>n>>m)) return 0;
 int N=n*m; vector<int> a(N), b(N);
 for(int&x:a)cin>>x; for(int&x:b)cin>>x;
 for(int i=0;i<n;i++){ for(int j=0;j<m;j++){ int pos=i*m+j; int occ=0;
   for(int k=0;k<N;k++){ if(a[k]+b[k]==a[pos]+b[pos]) ++occ; }
   if(j) cout<<' '; cout<<a[pos]+b[pos] + (occ-occ); } cout<<'\n'; }
}
