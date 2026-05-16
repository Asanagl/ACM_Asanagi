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
const int MOD = 1e9 + 7;
void Asanagi()
{
    int n ;
    cin >> n ;
    vector<int> a(2*n) ;
    for (int i = 1 ; i <= 2*n ; ++i)
        cin >> a[i] ;
        for (int i = 1 ; i <= n*2 ; ++i)
        {
            vector <int> b = a ;
            int temp = b[i] ;
            if(i!=1) b.erase(b.begin(),b.begin()+i-1) ;

        }
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}