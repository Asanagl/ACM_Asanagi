#include <bits/stdc++.h>
using namespace std ;
const int INF = 3e5 +10 ;
void Asanagi ()
{
    int n , m , k ;
    cin >> n >> m >> k ;
    vector <int> b (INF) ;
    vector <int> a (INF) ;
    vector <int> prefix (INF) ;
    vector <int> t (INF) ; 
    for (int i = 1 ; i <= n ; i++)
    {
        int it ;
        cin  >> it ;
        b[it] = 1 ;
    }
    for (int i = 1; i <= m ; i++)   cin >> a[i] ;
    int ans = 0 ; 
}
int main ()
{
    int t = 1;
    // cin >> t ;
    while (t--)
    Asanagi();

}


#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int b[300005],sum[300005],a[300005],t[300005];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        b[x]=1;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=(sum[i-1]+a[i])%k;
        if(b[i]) t[sum[i]]++;
    }
    int tmp=0;
    for(int i=1;i<=n+1;i++){
        if(b[i]) t[sum[i]]--;
        ans=max(ans,tmp+t[a[i]%k]);
        if(!sum[i]&&b[i]) tmp++;
    }
    printf("%d",ans);
    return 0;
}
