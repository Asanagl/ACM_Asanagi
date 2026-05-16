#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n ;
    cin >> n ;
    int a[100009];
    for(int t = 1 ; t <= n ; t++){
        a[t]=t;
    }
    if (n==1||n==2) cout << "-1" << endl ;
    else {
        for(int t=2;t<=(n-1)/2*2+1;t++){
            a[t]=t-1;
        }
        a[1]=(n-1)/2*2+1;
        if(n%2==0)swap(a[n],a[n-1]);
        for(int i =1 ; i <= n ; i++) {
            cout << a[i] << " " ;
        }
        cout  << endl;
    }
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}