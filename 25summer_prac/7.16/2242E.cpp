#include <bits/stdc++.h>
using namespace std ;
#define int long long
vector <int> bi (33 , 1) ;
void init ()
{
    for (int i = 1 ; i <= 31 ; i++)
    {
        bi[i] = (1 << (i-1)) ;
        // cout << bi[i] << " " ;
    }
}
int lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}
void solve ()
{
    int l , r , n ;
    cin >> l >> r >> n ;
    int x , y ;
    x = upper_bound(bi.begin() , bi.end() , l) - bi.begin() - 1LL ;
    y = upper_bound(bi.begin() , bi.end() , r) - bi.begin() - 1LL ;
    if (r - l == 1 && x == y)
    {
        vector <int> a (x) , b (y) ;
        for (int i = x-1 ; i >= 0 ; i--)
        {
            a[i] = l % 2 ;
            l /= 2 ;
            b[i] = r % 2 ;
            r /= 2 ; 
        }
        vector <int> ans (x) ;
        for (int i = 0 ; i < x ; i++)
        {
            ans[i] = a[i] & b[i] ;
        }
        int sum = 0 ;
        while (sum != n)
        {
            for (int i = 0 ; i < x; i++)
            {
                cout << ans[i] ;
                sum++ ;
                if (sum == n) break ;
            }
        }
        cout << endl ;
        return ;
    }
    // case1 /2 == >>1 ; %2 == 取最低位
    // cout << "x case:" << x << "  y case:" << y << endl ;
    if (x == y)
    {
        // cout << "case 1" ;
        int T = x ;
        vector <int> a (x) , b (y) ;
        for (int i = x-1 ; i >= 0 ; i--)
        {
            a[i] = l % 2 ;
            l /= 2 ;
            b[i] = r % 2 ;
            r /= 2 ; 
        }
        // for (int i = 0 ; i < x ; i ++)    cout  << a[i] ;  cout << endl ;
        // for (int i = 0 ; i < x ; i ++)    cout  << b[i] ;  cout << endl ;
        bool flag = false ;
        vector <int> ans (x) ;
        for (int i = 0 ; i < x ; i++)
        {
            if (flag) 
            {
                ans[i] = 0 ;
            }
            else if (a[i] == b[i]) 
            {
                ans[i] = a[i] ;
            } else
            {
                ans[i] = 0 ;
                flag = true ;
            }
        }
        int sum = 0 ;
        while (sum != n)
        {
            for (int i = 0 ; i < x; i++)
            {
                cout << ans[i] ;
                sum++ ;
                if (sum == n) break ;
            }
        }
        cout << endl ;
        return ;
    }
    // case 2 : 
    if (y - x == 1)
    {
        int T = lcm (x , y) ;
        r = bi[x+1] ;
        vector <int> a (T+1) , b (T+1) ;
        for (int i = x ; i >= 1 ; i--)
        {
            a[i] = l % 2 ;
            l /= 2 ;
        }
        for (int i = y ; i >= 1 ; i--)
        {
            b[i] = r % 2 ;
            r /= 2 ;
        }
        int q = T / x ;
        for (int j = 1 ; j < q; j++)
        {
            for (int i = 1 ; i <= x; i++)
            a[j*x + i] = a[i] ;
        }
        q = T / y ;
        for (int j = 1 ; j < q; j++)
        {
            for (int i = 1 ; i <= y; i++)
            b[j*y + i] = b[i] ;
        }
        vector <int> ans (T+1 , 0) ;
        for (int i = 1 ; i <= T ; i++)
        {
            if (a[i] == b[i] && a[i] == 1) ans[i] = 1;
            else ans[i] = 0 ; 
        }
        int sum = 0 ;
        while (sum != n)
        {
            for (int i = 1 ; i <= T; i++)
            {
                cout << ans[i] ;
                sum++ ;
                if (sum == n) break ;
            }
        }
        cout << endl ;
        return ;
    }
    // case 3
    if (y - x >= 2)
    {
        r = bi[y] ;
        l = bi[y-1] ;
        int T = lcm (y , y-1) ;
        vector <int> a(T+1) , b (T+1) ;
        for (int i = y - 1 ;i >= 1 ; i--)
        {
            a[i] = l % 2 ;
            l /= 2 ;
        }
        for (int i = y ;i >= 1 ; i--)
        {
            b[i] = r % 2 ;
            r /= 2 ;
        }
        int q = T / (y-1) ;
        for (int j = 1 ; j < q; j++)
        {
            for (int i = 1 ; i <= (y-1); i++)
            a[j*(y-1) + i] = a[i] ;
        }
        q = T / y ;
        for (int j = 1 ; j < q; j++)
        {
            for (int i = 1 ; i <= y; i++)
            b[j*y + i] = b[i] ;
        }
        vector <int> ans (T+1 , 0) ;
        for (int i = 1 ; i <= T ; i++)
        {
            if (a[i] == b[i] && a[i] == 1) ans[i] = 1;
            else ans[i] = 0 ; 
        }
        int sum = 0 ;
        while (sum != n)
        {
            for (int i = 1 ; i <= T; i++)
            {
                cout << ans[i] ;
                sum++ ;
                if (sum == n) break ;
            }
        }
        cout << endl ;
        return ;
    }
}
signed main ()
{
    init();
    int t ;
    cin >> t ;
    while (t--) solve ();
}