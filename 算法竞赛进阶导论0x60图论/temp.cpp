
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 2e8+10 ;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

struct Fenwick {
    int n;
    vector<int> bit;
    
    // 构造函数，下标从 1 开始，bit[0] 闲置
    Fenwick(int n_) : n(n_), bit(n_ + 1, 0) {}
    
    // 单点修改：在 idx 位置增加 delta
    void add(int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;  // lowbit，跳到父节点
        }
    }
    
    // 前缀和查询：[1, idx] 的和
    int sum(int idx) {
        int s = 0;
        while (idx > 0) {
            s += bit[idx];
            idx -= idx & -idx;  // lowbit，跳到前一个区间
        }
        return s;
    }
};

void Asanagi()
{
    int n ,q ;
    cin >> n  >> q ;
    vector <int> v (n) ;
    for (auto &it : v )cin >> it ;
    sort (v.begin() , v.end());
    while (q--)
    {
        int b ;
        cin >> b ;
        int k ;
        cin >> k ;
        int low = 0  , high = INF ;
        while (low <= high)
        {
            if (low == high) continue ;
            int mid = (low + high) / 2 ;
            int cnt = upper_bound (v.begin() , v.end() , b + mid)
                     - 
                      lower_bound(v.begin() , v.end() , b - mid) ;
            if (cnt >= k )  high = mid ;
            else low = mid + 1 ; 
        }
        cout << low << endl ;
        
    }
}   

signed main()
{
    IOS;
    int t = 1;
//     cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}


