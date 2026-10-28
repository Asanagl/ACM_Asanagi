#include <bits/stdc++.h>
using namespace std;
// per pair: full rescan by nested loop
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;const int n=(int)s.size();
 for(int i=0;i<n/2;++i){bool ok=true;for(int j=0;j<n/2;++j){if(s[j]!=s[n-1-j]){ok=false;break;}}
  if(!ok){cout<<"NO\n";return 0;}
  if(s[i]!=s[n-1-i]){cout<<"NO\n";return 0;}}
 cout<<"YES\n";return 0;}
