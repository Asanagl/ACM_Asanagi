#include <bits/stdc++.h>
using namespace std;
static int c[90000];
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
 int n,m; if(!(cin>>n>>m)) return 0;
 int N=n*m; vector<int> a(N), b(N);
 for(int&x:a)cin>>x; for(int&x:b)cin>>x;
 for(int i=0;i<n;i++){ for(int j=0;j<m;j++){
   for(int k=0;k<n;k++) for(int l=0;l<m;l++) c[k*m+l]=a[k*m+l]+b[k*m+l];
   if(j) cout<<' '; cout<<c[i*m+j]; } cout<<'\n'; }
}
