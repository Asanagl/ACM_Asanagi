#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const int inf = 2e5 + 10 ;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
int n;
set <int> s ;
void ins(int x , int cnt[] ) {
	if (cnt[x] == 0) {
		s.erase(s.find(x));
	}
	cnt[x]++;
}
void init ()
{
    s.clear();
    for (int i = 0 ; i <= n+1 ; i++)
    {
        s.insert(i) ;
    }
}
void Asanagi() {
    
    cin >> n;
    int idx01 = -1, idx02 = -1;
    vector<int> v(2 * n + 2);
    for (int i = 1; i <= 2 * n; i++) 
    {
        cin >> v[i];
        if (v[i] == 0 && idx01 == -1)
            idx01 = i;
        else if (v[i] == 0 )
            idx02 = i;
    }

    int ans = 1;
    int len = idx02 - idx01 + 1;

    if (len % 2 == 1) {
        init();
        int cnt[n + 1];
        memset (cnt , 0 , sizeof cnt) ;
        int mid = idx01 + len/2 ;
        int l = mid - 1 ; 
        int r = mid + 1 ;
        ins(v[mid] , cnt) ;
        while (l >= 1 && r <= 2 * n)
        {
            if (v[l] != v[r]) break ;
            ins(v[l] , cnt) ;
            l-- ; r++ ;
            ans = max (ans , *s.begin()) ;
        }
    } 
    else 
    {
        init();
        int cnt[n + 1];
        memset (cnt , 0 , sizeof cnt) ;
        int mid = idx01 + len/2 ;
        int l = mid -1 ; 
        int r = mid ;
        while (l >= 1 && r <=2 * n)
        {
            if (v[l] != v[r]) break ;
            ins(v[l] , cnt) ;
            l-- ; r++ ;
            ans = max (ans , *s.begin()) ;
        }
    }
    // idx1
    init();
    int cnt[n + 1];
    memset (cnt , 0 , sizeof cnt) ;
    int l = idx01;
    int r = idx01;
    while (l >= 1 && r <= 2 * n)
        {
            if (v[l] != v[r]) break ;
            ins(v[l] , cnt) ;
            l-- ; r++ ;
            ans = max (ans , *s.begin()) ;
        }
    
    // idx2
    init();
    memset (cnt , 0 , sizeof cnt) ;
    l = idx02;
    r = idx02;
    while (l >= 1 && r <= 2 * n)
        {
            if (v[l] != v[r]) break ;
            ins(v[l] , cnt) ;
            l-- ; r++ ;
            ans = max (ans , *s.begin()) ;
        }
    
    cout << ans << endl;
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
