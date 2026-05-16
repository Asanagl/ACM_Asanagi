#include <bits/stdc++.h>
using namespace std ;
#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define pb push_back
#define INF 3005
void Asanagi()
{
    ll n , m ;
    cin >> n >> m ;
    vector <string> a(INF) ;
    vector <string> b(INF) ;
    for (int i = 0 ; i < m ; i++)
    cin >> a[i] >> b[i] ;
    vector <string> c(INF) ;
    for (int i = 0 ; i < n ; i++)
    cin >> c[i] ;
    for (int i = 0 ; i < n ; i++)
    {
        string cnt = c[i] ;
        string ans;
        for (int j  = 0 ; j < m ; j++)
        {
            if (a[j] == cnt){
                ans = b[j] ;
                break ;
            }
        }
        cout << (ans.length() < cnt.length() ? ans : cnt ) << " " ;
    }

}



int main ()
{
    IOS ;
    int t = 1;
    // cin >> t ;
    while (t--)
    {
        Asanagi() ;
    }
}