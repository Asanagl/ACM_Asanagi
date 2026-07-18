#include <bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
void solve ()
{
    int n ;
    cin >> n ;
    string s ;
    cin >> s;
    bool flag = false ;
    int sum = -1 ;
    int len = 0 ;
    for (auto &it : s) 
    {
        if (it == '#') 
        {
            len++ ;
            sum = max(sum , len) ;
            flag = true ;
        } else 
        {
            len = 0 ;
        }
    }
    if (sum == -1)
    {
        cout << 0 << endl ;
        return ;
    }
    else 
    {
        cout << (sum+1)/ 2 << endl ;
        return ;
    }
}
signed main()
{
    int t ;
    cin >> t;
    while (t--)
    solve() ;
}