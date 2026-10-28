#include <bits/stdc++.h>
using namespace std ;
typedef long long LL;
void solve(){
    int n;
    cin >> n;
    vector<LL> a(n+1),pre(n+1),sum(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
        sum[i]=a[i]*(n-i+1);
    }

    if(n==1){
        cout << a[1] << endl;
        return;
    }

    vector<LL> b(n+1),sum1(n+1),pre1(n+1);
    b[1]=a[1];
    pre1[1]=b[1];
    sum1[1]=b[1]*n;
    for(int i=2;i<=n;i++){
        b[i]=a[n-i+2];
        pre1[i]=pre1[i-1]+b[i];
        sum1[i]=b[i]*(n-i+1);
    }

    LL mi=LLONG_MAX;
    for(int i=1;i<n;i++){
        mi=min(sum[i]+sum[i+1]+(pre[i]-a[i])*2,mi);
        mi=min(sum1[i]+sum1[i+1]+(pre1[i]-b[i])*2,mi);
    }
    cout << mi << endl;
}

int main ()
{
    int T;
    cin >> T;
    while(T--) solve();
}
