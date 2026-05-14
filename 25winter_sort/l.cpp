#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

struct segment {
    int l ;
    int r ;
    int id ;
};

bool cmp(const segment& a, const segment& b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r; 
}

void solve()
{   
    int n;
    cin >> n;
    vector<segment> seg(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> seg[i].l >> seg[i].r;
        seg[i].id = i + 1;
    }
    sort(seg.begin(), seg.end(), cmp);
    int ans_r = -1;
    int ans_id = -1;
    for (const auto& s : seg) {
        if (s.r <= ans_r) {
            cout << s.id << " " << ans_id << endl;
            return ;
        }
        if (s.r > ans_r) {
            ans_r = s.r;
            ans_id = s.id;
        }
    }
    cout << "-1 -1" <<  endl;
}




signed main()
{
    IOS;
    int t =1;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}

