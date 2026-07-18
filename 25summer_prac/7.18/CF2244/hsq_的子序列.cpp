#include <bits/stdc++.h>
using namespace std ;
#define int long long 

void solve ()
{
    int n ;
    string s ;
    cin >> n >> s;
    int needt = 0 , needs = 0 , needs2 = 0 ;
    int ans = 0 ;
    for (int i = n-1 ; i >= 0  ; i--)
    {
        if (s[i] == 't') needt++ ;
        if (s[i] == 's')
        {
            if (needs2 > 0)
            {
                needs2-- ;
                needs++ ;
            } else if (needt > 0)
            {
                needt-- ;
                needs2++ ;
            }
        }
        if (s[i] == 'u')
        {
            if (needs > 0 )
            {
                needs-- ;
                ans++ ;
            }
        }
        if (s[i] == '1')
        {
            if (needs > 0 )
            {
                needs-- ;
                ans++ ;
            } else needt++ ;
        }
    }
    cout << ans << endl ;
    
}
signed main ()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; 
    cin >> t ;
    while (t--) solve () ;
}

