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
const int N = 1005;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int a = 0 , b = 0 ;
    int n ;
    cin >> n ;
string s ;
    while ( getline(cin , s) )
    {
        string s1 = "Iroha love Kaguya";
        string s2 = "Kaguya love Iroha";
        string s3 = "Kaguya don't love Iroha" ;
        string s4 = "Iroha don't love Kaguya" ;
        if (s==s1)
        a++; 
        if (s==s2)
        b++;
        if(s == s3 || s == s4)
        {
            cout << "bad end" ;
            return ;
        }
    }
    if (a!=0 && b!=0) 
    {
        cout << "happy end" ;
    }
    else cout << "bad end" ;
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