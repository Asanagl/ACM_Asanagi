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
const ld EPS = 1e-9;using ll = long long ;
const int  N = 1e6+5 ;
struct node
{
    int sum = 0;
    int l , r;
    int tag = 0 ;
}tree[N * 4];
vector <int> a (N);
inline void update(int id)
{
    tree[id].sum = tree[id << 1].sum + tree[id << 1|1].sum ;
}
void maketree(int L , int R , int id)
{
    tree[id].l = L , tree[id].r = R ;
    if (L == R) {
        tree[id].sum = a[L] ;
        return ;
    }
    int mid = (L + R ) >> 1 ;
    maketree (L , mid , id << 1) ;
    maketree (mid+1 , R , id << 1|1) ;
    update(id) ;
}
int query(int L , int R , int id )
{
    if (tree[id].l >= L && tree[id].r <= R ) return tree[id].sum ;
    int mid = (tree[id].r + tree[id].l) / 2 ;
    int sum = 0 ;
    if ( L <= mid ) sum += query(L , R , id << 1 ) ;
    if ( R > mid ) sum += query(L , R , id << 1|1) ;
    return sum ;
}
void add (int id, int k , int idx)
{
    if (tree[id].l == tree[id].r)
    {
        tree[id].sum += k ;
        return ;
    }
    int mid = (tree[id].l + tree[id].r) >> 1 ;
    if (idx <= mid) add (id << 1, k , idx) ;
    else add (id << 1 | 1 ,k , idx) ;
    update(id) ;
}
void pushudown(int id)
{
    if(tree[id].tag){
        tree[2 * id].tag += tree[id].tag, tree[2 * id + 1].tag += tree[id].tag;
        tree[2 * id].sum += tree[id].tag * (tree[2 * id].r - tree[2 * id].l + 1);
        tree[2 * id + 1].sum += tree[id].tag * (tree[2 * id + 1].r - tree[2 * id + 1].l + 1);
        tree[id].tag = 0;
    }
}
void moreadd(int id,int l,int r,int k){
    if(l<=tree[id].l&&r>=tree[id].r){
        //如果查到子区间了
        tree[id].sum+=k*(tree[id].r-tree[id].l+1);//先修改这个区间
        tree[id].tag+=k;//然后给它打上懒标记
        //注：这里一定要分清顺序，先修改，再标记！
    }
    else{
        //如果需要继续向下查询
        pushudown(id);//一定要先把懒标记向下传
        int mid=(tree[id].l+tree[id].r)/2;
        //这里很像区间查询
        if(l<=mid) moreadd(id*2,l,r,k);
        if(r>mid) moreadd(id*2+1,l,r,k);    
        update(id);
    }
}
void Asanagi()
{
    int n , m;
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++)  cin >> a[i] ;
    maketree(1 , n , 1) ;
    while (m--)
    {
       int t , x , y ;
       cin >> t >> x >> y ;
       if (t==1) add (1 , y , x) ;
       else  cout << query (x , y , 1) << endl ;
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
