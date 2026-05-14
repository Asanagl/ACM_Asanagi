#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n , t ;
    cin >> n >> t ;
    vector <int> v (n) ;
    vector <int> bl (n,1) ;
    int ans = 0 ;
    int nsm = n ;
    int heyiwei = 999 ;
    for (int i = 0 ; i < n ; i++) cin>> v[i] ; 
    for (int i = 0 ; i < n ; i++)
        {
            if (v[i]<=t)
            {
                bl[i] = 0 ;
                ans++ ;
                if (ans==n)
                cout << i+1 << endl ;
                else cout << i+1 << " " ;
            }
        }
    while (ans!=n)
        {
            nsm = n - ans ;
            t = 0 ;
            for (int i = 0 ;i < n ; i++)
                {
                    if (bl[i]==0) continue ;
                    t+=v[i]/nsm ;
                }
            if (heyiwei!=999)
            {
                for (int i = 0 ; i < n ; i++)
                {
                    if (bl[i]==0) continue ;
                    if (v[i]<=t)
                    {
                        bl[i] = 0 ;
                        ans++ ;
                        if (ans==n)
                        cout << i+1 << endl ;
                        else cout << i+1 << " " ;
                        cout << "left" << endl ;
                    }
                }
                heyiwei = 999 ;
            } else
            {
                for (int i = n-1 ; i >= n ; i--)
                    {
                        if (bl[i]==0) continue ;
                        if (v[i]<=t)
                        {
                            bl[i] = 0 ;
                            ans++ ;
                            if (ans==n)
                            cout << i+1 << endl ;
                            else cout << i+1 << " " ;
                        }
            } heyiwei-- ;
            }
        }
}
