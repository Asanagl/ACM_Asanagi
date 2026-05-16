#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const int N = 2005;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

int fri[N] , siz[N] ;
int find (int n)
{
    if(fri[n] == n) return n ;
    else return fri[n] = find(fri[n]) ; 
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (siz[x] > siz[y])
    {
        fri[y] = x;
        siz[x] += siz[y];
    }
    else
    {
        fri[x] = y;
        siz[y] += siz[x];
    }
}

void Asanagi()
{
    int n , m  ;
    cin >> n >> m  ;
    for (int i = 1 ; i <= n*2 ;i++)
    {
        fri[i] = i ; siz[i] = 1 ;
    }
    for (int i = 0 ; i < m ; i++)
    {
        int x  , y ;
        char opt ;
        cin >> opt >> x >> y  ;
        if (opt == 'F')
        fri[find(x)] = find(y) ;
        else 
        {
            fri[find(x+n)] = find(y) ;
            fri[find(y+n)] = find(x) ;
        }
    }
    int ans = 0 ;
    for (int i = 1 ; i <= n  ;i++)
    if (fri[i] == i) ans++;
    cout << ans ;
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