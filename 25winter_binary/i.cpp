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

void Asanagi()
{
    ll n ;
    cin >> n ;
    if (n == 1) {
        cout << 1 << endl;
        return ;
    }
    ll target = n - 1;
    ll left = 1, right = INF*2 ;
    while (left < right) 
    {
        ll mid = (left + right) / 2;
        double value = mid * log10(mid);
        if (value >= target) 
        right = mid;
        else    left = mid + 1;

    }
    cout << left << endl;
}
signed main()
{
    IOS;
    int t = 1 ;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}