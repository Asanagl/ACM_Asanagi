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

int maxsum(const vector<int> &nums)
{ // 最大字段和
    int msum = nums[0], cnt = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        cnt = max(nums[i], cnt + nums[i]); // 状态转移
        msum = max(msum, cnt);
    }
    return msum;
}
void solve()
{
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    int sum = 0 ;
    for (auto &x : a)
    {
        cin >> x ;
        sum += x ;
    }
    vector<int> b ;//去头
    b.assign(a.begin() + 1, a.end()) ;
    vector<int> c ;//去尾
    c.assign(a.begin(), a.end() - 1) ;
    int temp = max(maxsum(b),maxsum(c)) ;

    if (sum > temp) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}


signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}