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



struct stct {
    int time; 
    int h; 
    int id;   
};

bool cmp(const stct& p1, const stct& p2) {
    long long val1 = 1LL * p1.h * p2.time;
    long long val2 = 1LL * p2.h * p1.time;
    
    if (val1 != val2) {
        return val1 > val2;
    }
    return p1.id < p2.id;
}

void solve()
{
    int n  ;
    cin  >> n ;
    vector<stct> problems;
    problems.reserve(n);
    for (int i = 1; i <= n; ++i) 
    {
        int a, b;
        cin >> a >> b;
        problems.push_back({a, b, i});
    }
    stct ans = problems[0];
    for (size_t i = 1; i < problems.size(); ++i) {
        if (cmp(problems[i], ans)) 
        {
            ans = problems[i];
        }
    }
    
    cout << ans.id << endl;
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

