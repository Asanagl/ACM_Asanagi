#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
 int n,m; if(!(cin>>n>>m)) return 0;
 int N=n*m; vector<int> a(N), b(N);
 for(int&x:a)cin>>x; for(int&x:b)cin>>x;
 for(int i=0;i<n;i++){ for(int j=0;j<m;j++){ int x=0,y=0;
   for(int p=0;p<n;p++) for(int q=0;q<m;q++) if(p==i&&q==j) x=a[p*m+q];
   for(int p=0;p<n;p++) for(int q=0;q<m;q++) if(p==i&&q==j) y=b[p*m+q];
   if(j) cout<<' '; cout<<x+y; } cout<<'\n'; }
}
