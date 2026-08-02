#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
#define int long long
const int inf = LLONG_MAX ;
signed main ()
{
    int n ;
    cin >> n ;
    vector <int> v (n+1) ;
    int sum = 0 ;
    int minn = inf ;
    for (int i = 1 ; i <= n ; i++)
    {
        int it ;
        cin >> it ;
        v[i] = it ;
        v.pb (it) ;
        sum += it ;
        minn = min (minn , it ) ;
    }
    int ans = 0 ;
    if (minn >= 0)
    {
        ans = n ;
        cout << ans << endl ;
        return 0 ;
    }
    if (sum < 0 )
    {
        cout << ans << endl ;
        return 0 ;
    }

    vector <int> prefix ( 2 * n + 1 );
    for (int i = 1 ; i <= 2*n ; i ++)
    {
        prefix[i] = v[i] + prefix[i-1] ;
    }
    deque <int> dq ;
    for (int i = 1 ; i <= n ; i ++)
    {
        while (!dq.empty() && prefix[dq.back()] >= prefix[i] )
        dq.pop_back() ;
        dq.pb(i) ;
    }
    for (int i = 0  ; i <n ; i++)
    {
        int l =  i  +1 ;
        int r = i + n  ;
        while (!dq.empty() && dq.front() < l)
        dq.pop_front();
        int minprefix = prefix[dq.front()] ;
        if(minprefix >= prefix[i])
        ans ++ ;
        int ni = r + 1 ;
        if (ni <= 2 * n )
        {
            while (!dq.empty() && prefix[dq.back()] >= prefix[ni] )
            dq.pop_back() ;
            dq.pb(ni) ;
        }
    }
    cout << ans << endl ;
}