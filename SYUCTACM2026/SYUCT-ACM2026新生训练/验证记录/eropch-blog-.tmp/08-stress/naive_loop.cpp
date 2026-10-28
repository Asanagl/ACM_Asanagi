#include <bits/stdc++.h>
int main(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::string s,t;std::cin>>s>>t;
 int n=s.size(),m=t.size();int ans=-1;
 for(int i=0;i+m<=n;++i){bool ok=true;for(int j=0;j<m;++j){if(s[i+j]!=t[j]){ok=false;break;}}if(ok){ans=i;break;}}
 std::cout<<ans<<'\n';}
