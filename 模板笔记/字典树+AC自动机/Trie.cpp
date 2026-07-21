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
const int maxn = 1e6+10 ;
using ll = long long ;
int n , cnt , ans ,vis[maxn] ;
string T ;
vector <string> s (maxn) ;
struct node 
{
    int child[26] ;
    int fail ;
    int end  ;
    void clear ()
    {
        memset(child , 0 , sizeof child) ;
        fail = 0 , end = 0;
    }
}Trie[maxn];
void insert(string s, int num)
{
    int u = 1 , len = s.size() ;
    for (int i = 0 ; i < len ; i++)
    {
        int v = s[i] - 'a' ;
        if (!Trie[u].child[v]) Trie[u].child[v] = ++cnt ;
        u = Trie[u].child[v] ;
    }
    Trie[u].end = num ;
}
void buildfail()
{
    for (int i = 0 ; i < 26 ; i++) Trie[0].child[i] = 1 ;
    queue<int> q ;
    q.push(1) ;
    Trie[1].fail = 0 ;
    while (!q.empty())
    {
        int u = q.front() ; q.pop() ;
        int fail = Trie[u].fail ;
        for (int i = 0 ; i < 26 ; i++)
        {
            int v = Trie[u].child[i] ;
            if (!v)
            {
                Trie[u].child[i] = Trie[fail].child[i] ;
                continue ;
            }
            Trie[v].fail = Trie[fail].child[i] ;
            q.push(v) ;
        }
    }
}
void query(string s){
    int u = 1, len = s.size();
    for(int i = 0; i < len; i++){
        int v = s[i] - 'a';
        int k = Trie[u].child[v];
        while(k > 1){
            if(Trie[k].end) vis[Trie[k].end]++;
            k = Trie[k].fail;
        }
        u = Trie[u].child[v];
    }
}
void clear(){
    for(int i=0; i<=cnt; i++) Trie[i].clear();
    for(int i=1; i<=n; i++) vis[i]=0;
    cnt=1; ans=0;
}
void Asanagi()
{
    while(1)
    {
    cin >> n ;
    if (n == 0 ) break ;
    clear() ;
    for (int i = 1 ; i  <= n ; i++)
    {
        string str ;
        cin >> str ;
        s[i] = str ;
        insert(str , i) ;
    }
    cin >> T ;
    buildfail();
    query(T) ;
    for (int i =  1 ; i <= n ; i ++)
    ans = max (ans , vis[i]) ;
    cout << ans << endl;
    for (int i = 1 ; i <= n ; i++)
    {
        if(vis[i] == ans) cout << s[i] << endl ; 
    }
}

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
