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
const ld EPS = 1e-9;
const int maxn = 2e5+10 ;
using ll = long long ;
int n , vis[maxn] ,  cnt = 0 , ans = 0 , Map[maxn] , in[maxn] ;
struct node {
    int child[26];
    int fail, flag, ans;
    node() { memset(child, 0, sizeof(child)); fail = flag = ans = 0; }
};
vector <node> trie (maxn) ;
vector <string> s (maxn) ;
string t ;
queue <int> q ;
void clear() {
    memset(in, 0, sizeof(int) * (cnt + 5));
    memset(vis, 0, sizeof(int) * (n + 5));
    trie.clear();
    trie.assign(2, node());
    cnt = 1;
}
void insert(string s , int num) 
{
    int u = 1 , l = s.size() ;
    for (int i = 0 ; i <  l ; i++)
    {
        int v = s[i] - 'a' ;
        if (!trie[u].child[v]) trie[u].child[v] = ++cnt ;
        u = trie[u].child[v] ;
    }
    if (!trie[u].flag) trie[u].flag = num ;
    Map[num] = trie[u].flag ;
}
void buildfail()
{
    for (int i = 0 ; i < 26 ; i++) trie[0].child[i] = 1 ;
    q.push(1) ;
    
    while (!q.empty())
    {
        int u = q.front() ; q.pop() ;
        int Fafail = trie[u].fail ;
        for (int i = 0 ; i < 26  ; i ++)
        {
            int v = trie[u].child[i] ;
            if (!v)
            {
                trie[u].child[i] = trie[Fafail].child[i] ;
                continue;
            }
            trie[v].fail = trie[Fafail].child[i];
            in[trie[v].fail] ++ ;
            q.push(v) ;
        }
    }
}
void topu ()
{
    for (int i = 1; i <= cnt; ++i)
    if (in[i] == 0) q.push(i);
    while (!q.empty())
    {
        int u = q.front() ; q.pop() ;
        vis[trie[u].flag] = trie[u].ans;
        int v = trie[u].fail;
        in[v]--;
        trie[v].ans += trie[u].ans;
        if (in[v] == 0) q.push(v);
    }
}

void query(string s)
{
	int u = 1, len = s.size();
	for(int i = 0; i < len; i++){
		u = trie[u].child[s[i] - 'a']; // 借助补全后的 Trie 图，直接走一步
		trie[u].ans++;               // 经过该节点一次，计数+1
	}
}

void Asanagi()
{
    cin >> n ;
    clear() ;
    for (int i = 1 ;i <= n ;i++)
    {
        string str ;
        cin >> str ;
        s[i] = str;
        insert(s[i] , i);
    }
    cin >> t ;
    buildfail() ;
    query(t) ;
    topu();
    for (int i = 1; i <= n ; i++)
    cout << vis[Map[i]] << endl;
    
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
