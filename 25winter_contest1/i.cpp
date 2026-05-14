#include <bits/stdc++.h>
using namespace std ;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define pb push_back
const int MAX= 2e5+5 ;
const int N = 505 ;

void solve()
{
    
    bitset <MAX * 2> isPrime ;
    int dist[MAX * 2] ;
    int n , m ;cin >> n >> m;
    vector <vector <int>> a(n,vector <int> (m));
    
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            cin >> a[i][j];
        }
    }
    isPrime.set();
    isPrime[0] = isPrime[1] = 0 ;
    for (int i = 2 ; i * i < MAX * 2 ; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i ; j < MAX * 2 ; j += i)
            {
                isPrime[j] = 0 ;
            }
        }
    }
    int last = -1 ;
    for (int i = (MAX * 2) - 1; i >= 0 ;i--)
    {
        if (isPrime[i]) last = i ;
        dist[i] = last -i ;
    }
    long long ans = 1e9 ;
    for (int i = 0 ;i <n;i++)
    {
        long long sum = 0 ;
        for (int j = 0 ; j < m ; j++)
        {
            sum += dist[a[i][j]] ;
        }
        ans = min(ans,sum) ;
    }
    for (int j = 0 ; j < m ; j++)
    {
        long long sum = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            sum += dist[a[i][j]] ;
        }
        ans = min(ans,sum) ;
    }
    cout << ans << endl ;
}



int main ()
{
    IOS ;
    int t = 1;
    // cin >> t ;
    while (t--)
    {
        solve() ;
    }
}