#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const int inf = 2e5 + 10 ;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
int n ;

vector <int> v (inf) ;
void solve()
{
    int mex = 1 ; 
    cin >> n ;
    int x = -1 , y , z ;
    for (int i = 0 ;i < 2*n ; i++)
    {
        cin >>v[i] ; 
        if (v[i]==0&&x==-1) x = i ;
        else if (v[i]==0) y = i ;
    }
    if ((x+y)%2==0)
    {
        z = (x+y)/2 ;
    }
    
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}