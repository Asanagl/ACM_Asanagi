#include <bits/stdc++.h>
using namespace std ;
#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define pb push_back
#define INF 3005
void solve()
{
    ll q ;
    cin >> q ;
    deque <pair<ll,ll>> dq ;
    ll offset = 0 ;
    while (q--)
    {
        int type ;
        cin >> type ;
        if (type == 1)
        {
            ll x ;
            cin >> x ;
            if (dq.empty())
            {
                dq.pb({0,x});
            }else 
            {
                ll head , length ;
                head = dq.back().first ;
                length = dq.back().second ;
                dq.pb({head + length , x}) ;
            }
        }
        else if (type == 2)
        {
            ll x = dq.front().second ;
            offset += x ;
            dq.pop_front() ;
        }
        else if (type == 3)
        {
            int x ;
            cin >> x ;
            cout << dq[x-1].first - offset << endl ;
        }
    }
}



// ?????????????????????????????????????????????????????????????????????????????????
// f12是飞行模式吗，我按我的飞行模式怎么出不来
//我故意找茬都想不出来这种话

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