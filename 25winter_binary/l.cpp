#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;



int dowbs(vector <int> &a, int k ,int n ){
        int l = 0;
        int r = n - 1;
        while(l < r)
        {
            int mid = (l + r + 1) / 2;
            if(a[mid] <= k)     l = mid;
            else    r= mid - 1;
        }
        if(a[l] > k) return -1;
        return a[l];
    }


int Binary_Search (int n ,int m,vector <int> &v)
{
    int l = 0 , r = v[n - 1 ]  ;
    int ans = 0 ;
    while (l <= r)
    {
        int mid = (l + r) / 2 ;
        int total = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            if (v[i] > mid)
            total += (v[i] - mid) ;
        }
        if (total < m)
        {
            r = mid - 1 ;
        }
        else
        {
            ans = mid ;
            l = mid + 1 ;
        }
    }
    return ans ;

}

void solve()
{
    int n  , m ;
    cin >> n >> m ;
    vector <int> t (n) ;
    for (auto &it : t) cin >> it ;
    sort (t.begin() , t.end()) ;
    cout << Binary_Search (n ,m, t) << endl ;
}
signed main()
{
    IOS;
    int t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}