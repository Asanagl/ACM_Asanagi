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
    int x, y, n;
    cin >> x >> y >> n;

    if (y * n <= x) 
    {
        cout << "0.0" << endl;
        return ;
    }

    ld left = 0.0, right = 10.0; 
    ld mid;
    for (int i = 0; i < 100; ++i) {
        mid = (left + right) / 2;
        ld sum = 0.0;
        ld ans = 1.0 + mid;
        ld f = 1.0;
        for (int j = 0; j < n; ++j) {
            f /= ans; 
            sum += y * f;
        }
        if (sum > x) {
            left = mid; 
        } else {
            right = mid;
        }
    }
    cout << fixed << setprecision(1) << mid * 100 << endl;
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