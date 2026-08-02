#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
void solve ()
{
    unordered_map<int , int> ump ;
    int n ;
    cin >> n  ;
    for (int i = 0 ; i < n ; i ++)
    {
        int it ;
        cin >> it ;
        ump [it] ++;
    }
    int maxn = 0 ;
    int sum = 0 ;
    vector <int> v  ;
    for (auto &it : ump) 
    {
        v.pb (it.second) ;
        maxn = max (maxn , it.second) ;
        sum += it.second ;
    }
    if (maxn >= sum - maxn)
    cout << maxn - (sum - maxn) << endl ;
    else cout << sum % 2 << endl ;
    
}
int main ()
{
    int t = 1 ;
    cin >> t ;
    while (t--)
    solve () ;
}