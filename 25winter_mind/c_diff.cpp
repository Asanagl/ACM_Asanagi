#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void solve()
{
    int n ;
    int a = 0 ;
    int osum = 0 , zsum = 0 ;
    string str ;
    cin >> str ;
    a = str.length() ;
    for (int i = 0 ; i < a ; i++)
    {
        if (str[i] == '0')zsum++ ;
        else osum++ ;
    }
    if (a <= 2 ||osum==0 || zsum==0)
    cout << 0 << endl;
    else {
        if (osum > zsum)cout << zsum << endl;
        else if (osum < zsum)cout << osum<< endl;
        
        else if (osum == zsum){zsum-- ;
        cout << zsum << endl;}
    }


}

signed main()
{
    IOS;
    int t  ;
    // t = 1 ; 
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}