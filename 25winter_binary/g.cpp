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
            if(a[mid] < k)     l = mid;
            else    r= mid - 1;
        }
        if(a[l] > k) return -1;
        return a[l];
    }


int Binary_Search (int n , int x ,vector <int> &v)
{
    int r = n - 1 , l = 0 ;
    while (r >= l)
    {
        int mid = (l + r) / 2 ;
        if (v[mid] == x)
        {
            return mid ;
        }
        else if (v[mid] > x)
        {
            r = mid - 1 ;
        }
        else
        {
            l = mid + 1 ;
        }
    }
    return -1 ;

}

void solve()
{
    int n ;
    cin >> n ;
    vector <int> v(n) ;
    for (auto &it : v) cin >> it ;
    int m ;
    cin >> m ;
    sort (v.begin() , v.end()) ;
    for (int i = 0 ; v[i]<=m/2 ; i++)
    {
        int x = m - v[i] ;
        int ans = Binary_Search (n , x , v) ;
        if (ans != -1)
        {
            cout << v[i] << " " << v[ans] << endl ;
            return ;
        }
    }
    cout << "No" << endl ;

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