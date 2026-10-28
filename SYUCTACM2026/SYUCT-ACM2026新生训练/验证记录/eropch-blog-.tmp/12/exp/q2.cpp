#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
 int n,m; if(!(cin>>n>>m)) return 0;
 int N=n*m; vector<int> a(N), b(N);
 for(int&x:a)cin>>x; for(int&x:b)cin>>x;
 vector<int> c; c.reserve(N);
 for(int i=0;i<n;i++)for(int j=0;j<m;j++) c.insert(c.begin(), a[i*m+j]+b[i*m+j]);
 for(int i=0;i<n;i++){for(int j=0;j<m;j++){ if(j)cout<<' '; cout<<c[(n-1-i)*m+(m-1-j)]; } cout<<'\n';}
}
