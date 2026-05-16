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

void Asanagi()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ;
    for (auto &it : v ) cin >> it ;
    sort (v.begin(),v.end());
    int l = 0 ; 
    int r = 0 ;
    int ansl = 0 ; 
    int ansr = -1 ;
    for (l = 0 ; l < n-2 ; l++)
    {
        r = max(r, l+2) ;
        while (r < n && v[l] + v[l+1] > v[r])
        r++ ;
        if (r - 1 - l + 1 > ansr - ansl +1)
        {
            ansl = l ;
            ansr = r-1;
        }
    }
    if (ansr - ansl + 1 < 3)
    {
        cout << 0 << endl ;
    }else {
        cout <<(ansr-ansl+1) ;
        for (int i = ansl ; i <= ansr ; i++)
        cout << " " << v[i] ;
        cout << endl ;
    }
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