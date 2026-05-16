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
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int zheng  = 0 , fu = 0 , z = 0 ;
    int n ;
    cin >> n ;
    vector <int> v (n) ;
    for (auto &it : v) 
    {
        cin >> it ;
        if (it < 0) fu++;
        else if (it > 0) zheng++;
        else if (it == 0) z++ ;
    } 
    if (zheng == 0 && z > 0 )
    {
        cout << 0 ; return ;
    }
    if (n == 1 || z == n) 
    {
        for (auto &it : v) cout << it << " " ;
        return ;
    }
    sort(v.begin(),v.end()) ;
    bool flag = false ;
    if (fu%2==0) flag = true ;
    for (int i = 0 ; i < n ; i++)
    {
        if (v[i]==0) continue ;
        if (flag || fu == 0) cout << v[i] << " " ;
        else 
        {
            if (fu == 1) {fu--;continue ;}
            else cout << v[i] << " " ;
        }
        if (v[i]<0) fu--;
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