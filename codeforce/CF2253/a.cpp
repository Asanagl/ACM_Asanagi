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

bool prime (int n)
{
    if (n == 2 || n == 3) return true ;
    if (n == 1 || n % 2 == 0) return false ;
    for (int i = 3 ; i * i <= n ; i+=2) 
    {
        if (n % i == 0) return false ;
    }
    return true;
}
void Asanagi()
{
    int n ;
    cin >> n ;
    if (prime(n+1)) cout << "YES" ;
    else cout << "NO" ;
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
