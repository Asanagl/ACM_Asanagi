#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
const int  N = 3e5+5 ;
struct nagtree {

int tree[4 * N] ;
inline void update (int id)
{
    tree[id] = tree[id << 1] + tree[id << 1|1] ;
}
void buildtree(int l , int r , int id , int n){
    if (l == r) {
        if (l == 0)
            tree[id] = n;
        else
            tree[id] = 0;
        return;
    }
    int mid=(l+r)>>1;
    buildtree (l , mid , id << 1 , n) ;
    buildtree (mid+1 , r , id << 1|1 , n) ;
    update(id) ;
}
inline void insert (int l , int r , int k , int id , int p)
{
    if (l == r) 
    {
        tree[id]+=p ;
        return ;
    }
    int mid = (l + r) >> 1 ;
    if (k <= mid) insert (l , mid , k , id << 1 , p ) ;
    else insert (mid+1 , r , k , id << 1|1 , p ) ;
    update(id) ; 
}
inline void del (int l , int r , int k , int id , int p)
{
    if (l == r) 
    {
        tree[id]-=p ;
        return ;
    }
    int mid = (l + r) >> 1 ;
    if (k <= mid) del (l , mid , k , id << 1 , p ) ;
    else del (mid+1 , r , k , id << 1|1 , p) ;
    update(id) ; 
}
inline int query (int l , int r , int L , int R , int id ) // 查询 l - r
{
    if (l > r) return 0 ;
    if (L >= l && R <= r)
        return tree[id];
    int mid = (L + R) / 2, sum = 0;
    if (l <= mid) sum += query (l , r , L , mid , id << 1) ;
    if (r > mid) sum += query ( l , r , mid+1 , R ,id << 1 |1 ) ;
    return sum;
}
} ta, tb;
int lb[N] , lw[N] ;
void Asanagi()
{
    int n , q ;
    cin >> n >> q ;
    
    ta.buildtree(0 , q , 1 , n) ;
    tb.buildtree(0 , q , 1 , n) ;
    memset(lb , 0 , sizeof lb) ;
    memset(lw , 0 , sizeof lw) ;
    int ans = 0 ;
    for (int t = 1 ; t <= q; t++ )
    {
        int op ;
        cin >> op ;
        if (op == 1 )
        {
            int r ;
            cin >> r; 
            int prev = lb[r] ;
            int devprev = tb.query(0 , prev-1 , 0 , q , 1) ;
            ans += (n - devprev) ;
            ta.del(0 , q , prev , 1 , 1) ;
            ta.insert(0 , q , t , 1 , 1) ;
            lb[r] = t ;
        }
        else 
        {
            int c ;
            cin >> c ;
            int prev = lw[c] ;
            int devprev = ta.query(prev+1 , q , 0 , q , 1)  ;
            ans-=devprev;
            tb.del(0 , q , prev , 1 , 1) ;
            tb.insert(0 , q , t , 1 , 1) ;
            lw[c]=t;
        }
        cout << ans << endl;  
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
