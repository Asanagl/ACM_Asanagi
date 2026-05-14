#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    int a[n] , ans[n] ;
    cin >> n ;
    for (auto &i : a) cin >> i ;
    sort(a , a + n) ;
    int min_val = a[0] ,max_val = a[n - 1] ;
    for (int i = 0 ; i < n ; i++)
    {
        if (a[i]<=0)
        {
            ans[i] = a[i] * min_val;
        }
        else {
            ans[i] = a[i] * max_val ;
        }
    }

}