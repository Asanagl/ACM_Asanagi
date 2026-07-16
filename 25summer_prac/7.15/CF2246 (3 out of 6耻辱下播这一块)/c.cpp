#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define pb push_back
const int MOD = 1e9 + 7 ;
const int N = 2e5+10 ;
map<int , int> mp ;
inline int fast(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res *= x;
        x *= x;
        y >>= 1;
        res %= MOD ;
        x %= MOD ;
    }
    return res;
}
void solve ()
{
    int n ;
    cin >> n ;
    vector <int> v (n+1) ;  
    int m = 0 ;
    set<int>st ;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
        if (v[i] == -1 ) m++ ;
        mp[v[i]]++ ;
        st.insert(v[i]) ;
    }
    int len = st.size() ;
    vector <int> v1 (1) ;
    int sum = 0;
    for (auto &it : st ) 
    {
        v1.pb(it) ;
    }
    v1[0] = -1 ;
    for (int i = 1 ; i <= len ; i++ )
    {
        if (v1[i] - v1[i-1] == 1) sum++ ;
    }
    if (m == 0) 
    {
        cout << fast(2 , n - len) << endl ;
    }else{
        int ans = fast(2 , n - len)  ;
        ans = ans * (sum + 1);
        cout << ans % MOD << endl ;
        // cout << "n - len " << n << " " << len << endl ;
    }
    // cout << "sum ->" << sum << " len ->" << len << endl;
    
}
signed main ()
{
    int t ;
    cin >> t ;
    while (t--)
    solve();
}
// ! 我们把数组分为-1段和正整数段
// 观察题目注意到：
// 他要求的交错和对于后半段的正整数来说，由于正整数是非递减排序，所以只能取偶数个数，我们要么取一对数，要么取多对数
// 对于正整数只需要寻找一种数的同种数有多少，
// * 题干中给了有-1的条件，那么我们不仅要在后半段的交错数中取0，还需要交错数为-1的组
// 1 1 1 3 3 3 5 5 5
// -1 -1 -1 -1 -1 
// 还有一个问题：$C_n^0 + C_n^2 + C_n^4 + \dots$ 的值是多少？
// 根据二项式定理：$(1+x)^n = \sum_{k=0}^{n} C_n^k x^k$。
// 分别带入 $x=1, x=-1$ 再作差，可得原式等于 $2^{n-1}$。