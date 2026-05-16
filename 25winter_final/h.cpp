#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;


void Asanagi()
{
    int n ;
    cin >> n ;
    vector <int> v (n+2) ;
    for (int i = 0 ; i < n ; ++i)
    {
        int x ;
        cin >>  x ;
        v[x] ++ ;
    }
    for (int i = 1  ; i <=n ; ++i) 
    {
        if (v[i]> 2)
        {
            v[i+1] += v[i] -2 ;
            v[i] =2 ;
        }
    }
    for (int i =1 ; i <=n ;++i)
    {
        if (v[i] % 2 == 1)
        {
            cout << "No" << endl ;
            return ;
        }
    }
    cout << "Yes" << endl ;
    
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}