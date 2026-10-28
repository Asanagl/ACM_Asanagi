#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;const size_t n=s.size();
 for(size_t i=0;i<n;++i){string rev;rev.reserve(n);for(size_t j=n;j-->0;)rev.push_back(s[j]);
  if(s[i]!=rev[i]){cout<<"NO\n";return 0;}}
 cout<<"YES\n";return 0;}
