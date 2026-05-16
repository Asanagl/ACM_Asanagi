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
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
const int dx[8] = {1,0,-1,0,1,-1,1,-1} ;
const int dy[8] = {0,1,0,-1,1,-1,-1,1} ;
int n , m ;
int vis[110][110] ;
int ysnb[110][110] ;
void Asanagi()
{
    int n ;
    string s ;
    map<char, char> mp;
    cin >> n >> s;
    string r ;
    int pos = 1 ;
    r = s ;
    sort (r.begin(),r.end()) ;
    for (int i = 1 ; i < r.size(); i++)
    {
        if (r[i]!=r[i-1]) r[pos++]=r[i] ;
    }
    for (int i = 0 ; i < pos ; i++)
    {
        mp[r[i]] = r[pos-i-1] ;
    }
    for (int i = 0 ; i < n ;  i++) cout << mp[s[i]] ;
    cout << endl ;
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}