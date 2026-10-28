#include <bits/stdc++.h>
int main(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::string s,t;std::cin>>s>>t;
 int n=s.size(),m=t.size();int ans=-1;
 for(int i=0;i+m<=n;++i){if(s.substr(i,m)==t){ans=i;break;}}
 std::cout<<ans<<'\n';}
