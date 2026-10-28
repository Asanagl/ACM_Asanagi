#include <bits/stdc++.h>
int main(){std::string s,t;std::cin>>s>>t;int n=s.size(),m=t.size();
for(int i=0;i+m<=n;++i){int j=0;while(j<m&&s[i+j]==t[j])++j;if(j==m){std::cout<<i<<"\n";return 0;}}
std::cout<<-1<<"\n";}
