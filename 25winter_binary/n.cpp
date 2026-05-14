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

int L , N , M ;
vector <int> rocks;
bool check(int d) {
    int l = 0;    
    int changed = 0;  
    
    for (int i = 0; i < N; i++) 
    {
        if (rocks[i] - l < d) 
        {
            changed++;
            if (changed > M) return false;
        } else {
            l = rocks[i];
        }
    }
    if (L - l < d) 
        return false;

    return (changed <= M);
}

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
    cin >> L >> N >> M;
    rocks.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> rocks[i];
    }
    int l = 1, r = L;
    while (l < r) 
    {
        int mid = l + (r - l + 1) / 2; 
        if (check(mid))     l = mid;  
            else    r = mid - 1;
    }
    cout << l << endl;
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