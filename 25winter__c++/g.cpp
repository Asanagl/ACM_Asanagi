#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n ;
    cin >> n ;
    cin.ignore() ;
    string s ;
    getline(cin,s) ;
    int cnt = 0 ;
    int temp = 0 ;
    for (auto &it : s )
    {
        if (it ==' ')
        {
            cout << temp << endl;
            cnt = max(cnt,temp) ;
            temp = 0 ;
        }else if (it>='A' && it<='Z')
        temp++;
    }
    cout << max(cnt,temp) << endl ;

}

signed main()
{
    IOS;
    int t = 1 ;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}