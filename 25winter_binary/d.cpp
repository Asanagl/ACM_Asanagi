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

int Binary_Search (int n , int x ,vector <int> &v)
{
    int r = n - 1 , l = 0 ;
    while (r >= l)
    {
        int mid = (l + r) / 2 ;
        if (v[mid] == x)
        {
            ; 
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
    return 0 ;

}

void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) 
    {
        int num;
        cin >> num;
        mp[num]++;
    }
    for (int i = 0; i < m; i++) 
    {
        int x;
        cin >> x;
        cout << mp[x] << endl;
    }
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