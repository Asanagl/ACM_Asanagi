#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;const size_t n=s.size();
 for(size_t i=0;i<n/2;++i){long long bad=0;for(size_t j=0;j<n/2;++j)bad+=(s[j]!=s[n-1-j]);
  if(bad!=0){cout<<"NO\n";return 0;}}
 cout<<"YES\n";return 0;}
