#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
// #define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const int N = 2e5 ;
const ld EPS = 1e-9;
using ll = long long ;
bool check(vector<int>& v, int n, vector<int>& vis, int& tag) {
    tag++;
    for (int i = 1; i <= n; ) {
        int cur = v[i];
        if (vis[cur] == tag) return false;
        vis[cur] = tag;
        while (i <= n && v[i] == cur) i++;
    }
    return true;
}
void Asanagi()
{
    int n ;
    cin >> n ;
    vector <int> v (n+1) ;
    unordered_map<int, int> mp ; 
    vector <int> numdeng (n+1) ; 
    set <int> st ;
    for (int i = 1 ; i <= n ;i++)
    {
        cin >> v[i] ;
        st.insert(v[i]) ;
    }//离散化处理方便后续操作
    // !如果使用unordered_map会退化到O(n)
    vector<int> tmp(v.begin() + 1, v.end());
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    int c = tmp.size();
    
    for (int i = 1; i <= n; i++) {
        v[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
    }
    vector<int> vis(c, 0);
    int tag = 0;
    // for (int i = 1 ; i <= n ; i++)
    // {
    //     cout << v[i] << " "  ;
    // } cout << endl ;
    // 观察到如果同一个数，有三个以上的独立联通块那么就无解，
    // 对于不同的数，如果不连续的元素的集合数量大于2，也无解
    if (check(v, n, vis, tag)) {
        cout << "YES" << endl ;
        return ;
    }
    for (int i = 1 ; i <= n ;)
    {
        numdeng[v[i]]++ ;
        if (numdeng[v[i]] > 3) 
        {
            cout << "NO" << endl ;
            // cout << 1 ;
            return ;
        }
        int j = i ;
        while (i <= n && v[i] == v[j])
        {
            i++;
        }
    }
    vector<int> bad;
    for (int x = 0; x < c; x++)   
        if (numdeng[x] > 1) bad.push_back(x);
    if (bad.size() > 2) {
        cout << "NO" << endl;
        return;
    }
    // 收集候选交换位置
    set<int> cand;
    int i = 1;
    while (i <= n) {
        int cur = v[i];
        int L = i;
        while (i <= n && v[i] == cur) i++;
        int R = i - 1;
        if (numdeng[cur] > 1) {
            cand.insert(L);
            cand.insert(R);
            if (L > 1) cand.insert(L - 1);
            if (R < n) cand.insert(R + 1);
        }
    }
    vector<int> pos(cand.begin(), cand.end());
    int sz = pos.size();
    for (int x = 0; x < sz; x++) {
        for (int y = x + 1; y < sz; y++) {
            swap(v[pos[x]], v[pos[y]]);
            if (check(v, n, vis, tag)) {
                cout << "YES" << endl;
                return;
            }
            swap(v[pos[x]], v[pos[y]]);
        }
    }
    cout << "NO" << endl ;
} 

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
