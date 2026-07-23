#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
const int maxn = 1e5 + 10;         
const int maxt = 3e5 + 10;         
const int MOD = 998244353;
using ll = long long ;

struct node
{
    int child[26];
    int fail;
    int flag;
    int up;
    int len;
    node()
    {
        memset(child, 0, sizeof(child));
        fail = 0;
        flag = -1;
        up = 0;
        len = 0;
    }
};

vector<node> trie;
int cnt = 0;
int n, q;
char S[maxn];
ll a[maxn];
vector<string> patterns;
unordered_map<string, int> pat2id;
int indx_S[maxt];

vector<int> occ[maxt];
int Map[maxt];

ll p[maxn];
ll pre_min[maxn];
ll suf_max[maxn];
ll sum_p[maxn];

void init()
{
    trie.clear();
    trie.emplace_back();
    trie.emplace_back();
    cnt = 1;
    for (int i = 0; i < 26; ++i)
        trie[0].child[i] = 1;
    trie[1].fail = 0;
    trie[1].up = 0;
}
void insert(string s, int num)
{
    int u = 1;
    for (char ch : s)
    {
        int v = ch - 'a';
        if (!trie[u].child[v])
        {
            trie[u].child[v] = ++cnt;
            trie.emplace_back();
        }
        u = trie[u].child[v];
    }
    trie[u].flag = num;
    trie[u].len = s.size();
}

void buildfail()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i)
        {
            int v = trie[u].child[i];
            if (!v)
            {
                trie[u].child[i] = trie[trie[u].fail].child[i];
            }
            else
            {
                trie[v].fail = trie[trie[u].fail].child[i];
                if (trie[trie[v].fail].flag != -1)
                    trie[v].up = trie[v].fail;
                else
                    trie[v].up = trie[trie[v].fail].up;
                q.push(v);
            }
        }
    }
}
void query()
{
    int u = 1;
    for (int i = 1; i <= n; ++i)
    {
        u = trie[u].child[S[i] - 'a'];
        for (int v = u; v; v = trie[v].up)
        {
            if (trie[v].flag != -1)
            {
                occ[trie[v].flag].push_back(i);
            }
        }
    }
}
void prework()
{
    p[0] = 0;
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    pre_min[0] = p[0];
    for (int i = 1; i <= n; ++i)
        pre_min[i] = min(pre_min[i - 1], p[i]);
    suf_max[n] = p[n];
    for (int i = n - 1; i >= 0; --i)
        suf_max[i] = max(suf_max[i + 1], p[i]);
    sum_p[0] = 0;
    for (int i = 1; i <= n; ++i)
        sum_p[i] = sum_p[i - 1] + p[i];
}

void Asanagi()
{
    string t ;
    cin >> n >> q;
    cin >> t ;
    for (int i = 0 ; i < t.size() ; i++)
    S[i+1] = t[i] ;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    patterns.push_back("");
    int pat_cnt = 0;
    for (int i = 1; i <= q; ++i)
    {
        string t;
        cin >> t;
        auto &id = pat2id[t];
        if (!id)
        {
            id = ++pat_cnt;
            patterns.push_back(t);
        }
        indx_S[i] = id;
    }
    init();
    for (int i = 1; i <= pat_cnt; ++i)
    {
        insert(patterns[i], i);
    }
    buildfail();
    query();
    prework();
    vector<ll> max_ans(pat_cnt + 1, -LINF);
    vector<ll> sum_ans(pat_cnt + 1, 0);

    for (int idx = 1; idx <= pat_cnt; ++idx)
    {
        auto &v = occ[idx];
        if (v.empty())
            continue;
        int len = patterns[idx].size();

        for (auto &r : v)
        {
            int l = r - len + 1;
            ll cand = suf_max[r] - pre_min[l - 1];
            if (cand > max_ans[idx])
                max_ans[idx] = cand;
        }

        ll curL = -1;
        int start_r = -1;
        ll total = 0;
        for (auto &r : v)
        {
            int L = r - len + 1;
            if (L > curL)
            {
                if (curL != -1)
                {
                    int cnt = r - start_r;
                    ll sum_pr = sum_p[r - 1] - sum_p[start_r - 1];
                    ll contrib = sum_pr - cnt * p[curL - 1];
                    total = (total + contrib) % MOD;
                }
                curL = L;
                start_r = r;
            }
        }
        if (curL != -1)
        {
            int cnt = n - start_r + 1;
            ll sum_pr = sum_p[n] - sum_p[start_r - 1];
            ll contrib = sum_pr - cnt * p[curL - 1];
            total = (total + contrib) % MOD;
        }
        sum_ans[idx] = (total % MOD + MOD) % MOD;
    }
    for (int i = 1; i <= q; ++i)
    {
        int idx = indx_S[i];
        cout << max_ans[idx] << ' ' << sum_ans[idx] << '\n';
    }
}

signed main() {
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) {
        Asanagi();
    }
    return 0;
}