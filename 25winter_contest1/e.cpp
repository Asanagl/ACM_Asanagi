#include <bits/stdc++.h>
using namespace std ;
#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define pb push_back
#define INF 3005
void Asanagi()
{
    int n ;
    cin >> n ;
    vector <int> a(35) ,b (35) ;
    for (int i = 0 ; i < n ; i ++)
    cin >> a[i] >> b[i] ;
    int cnt = 0 ; 
    for (int i = 0 ; i < n ;i++)
    {
        for (int j = 0 ; j < n ;j++)
        {
            if (i != j && a[i] == b[j])
            cnt ++ ;
        }
    }
    cout << cnt << endl ;
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