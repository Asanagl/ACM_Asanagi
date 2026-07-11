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
const int N = 1e6 + 5 ;
int tree[4 * N] ;
inline void update (int id)
{
    tree[id] = tree[id << 1] + tree[id << 1|1] ;
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
    if (L >= l && R <= r)
        return tree[id];
    int mid = (L + R) / 2, sum = 0;
    if (l <= mid) sum += query (l , r , L , mid , id << 1) ;
    if (r > mid) sum += query ( l , r , mid+1 , R ,id << 1 |1 ) ;
    return sum;
}
void Asanagi()
{
    int n , k ;
    cin >> n >> k ;
    while (k--)
    {
        char ch ;
        cin >> ch ;
        if (ch == 'A')
        {
            int m ;
            cin >> m ;
            cout << query(1 , m , 1 , n , 1) << endl ;
        }else if (ch == 'B')
        {
            int m , p ;
            cin >> m >> p ;
            insert(1 , n ,m ,1 , p) ;
        }else if (ch == 'C')
        {
            int m , p ;
            cin >> m >> p ;
            del(1 , n , m , 1 , p) ;
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
