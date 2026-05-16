#include <bits/stdc++.h>
using namespace std ;
#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define pb push_back
#define INF 3005
void Asanagi()
{
    ll n , k , q ;
    cin >> n >>  k >> q ;
    vector <ll> pos (k+1) , time (k+1) ;
    pos[0] = 0 , time[0] = 0 ;
    for (int i = 1 ; i <= k ; i++) cin >> pos[i] ;
    for (int i = 1 ; i <= k ; i++) cin >> time[i] ;
    while (q--)
    {
        ll a ;
        cin >> a ;
        ll idx = upper_bound(pos.begin() , pos.end() , a) - pos.begin() -1;
        if (pos[idx] == a )
        {
            cout << time[idx] << " ";
            continue ;
        }
        ll lpos = pos[idx] , rpos = pos[idx+1] ;
        ll ltime = time[idx] , rtime = time[idx+1] ;
        ll ans = ltime + (a - lpos) * (rtime - ltime) / (rpos - lpos) ;
        cout << ans << " " ;
    }
    cout << endl ;
}



int main ()
{
    IOS ;
    int t ;
    cin >> t ;
    while (t--)
    {
        Asanagi() ;
    }
}