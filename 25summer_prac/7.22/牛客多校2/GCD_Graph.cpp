#include <bits/stdc++.h>
using namespace std ;
const int N = 1e7 + 7 ;
int primes[N / 10] , cnt ;
bool vis [N] ;
int factor[20] , num ;
int dp[505] ;
void gprimes(int n)
{
    for (int i = 2 ;i <= n ; i++)
    {
        if (!vis[i]) primes[++cnt] = i ;
        for (int j = 1 ; j <= cnt && i * primes[j] <= n ; j++)
        {
            vis[i * primes[j]] = 1 ;
            if (i % primes[j] == 0) break ;
        }
    }
}
void gfactors(int n )
{
    num = 0 ;
    int temp = n ;
    for (int i = 1 ; primes[i] * primes[i] <= temp && i <= cnt ; i++)
    {
        if (temp % primes[i] == 0 )
        {
            factor[num++] = primes[i] ;
            while (temp % primes[i] == 0) temp /= primes[i] ;
        }
    }
    if (temp > 1) factor[num++] = temp ;
}
int f (int m , int num )
{
    if (m <= 0 ) return 0 ;
    int res = 0 ;
    for (int i = 1 ; i < (1LL << num) ; i++)
    {
        int sum = 0 ; int temp = 1; 
        for (int j = 0 ; j < num ; j++)
        {
            if ((i >> j) & 1 )
            {
                sum ++ ;
                temp *= factor[j] ;
            }
        }
        if (sum % 2) res += m / temp ;
        else res -= m /temp ;
    }
    return res ;
}
void solve()
{
    int l , r , n ;
    cin >> l >> r >> n ;
    gfactors(n) ;
    int ts = 0 ;
    int B = 450 ;
    int spilt = max (l , n- B) ;
    if (spilt < n)
    {
        for (int i = n -1; i >= spilt ;i--)
        {
            int cur = __gcd(i , n) ;
            for (int k = 1 + i; k < n ; k++)
            {
                if (cur <= 2) break ;
                cur = min (cur , __gcd(i , k)+ dp[n-k]) ; 
            }
            dp[n-i] = cur ;
            if (i >= l && i <= r) ts += cur ;
        }
    }
    int far_r = min (r , spilt - 1) ;
    if ( l <= far_r )
    {
        int len = far_r - l + 1 ;
        int ncc = f(far_r , num) - f(l - 1 , num) ;
        int cc = len - ncc ;
        ts += (cc + ncc * 2 ) ;
    }
    cout << ts << endl ;
}
signed main ()
{
    gprimes(N) ;
    int t; 
    cin >> t ;
    while (t--)
    solve() ;
}