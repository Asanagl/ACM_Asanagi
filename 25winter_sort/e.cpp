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

struct student
{
    int score ;
    int id ;
};
void solve()
{
    int n;
    cin >> n ;
    vector<student> a(n) ;
    for (int i = 0 ;i < n ;i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            int x ;
            cin >> x ;
            a[i].score+=x ;
        }
        a[i].id = i+1 ;
    }
    sort(a.begin(), a.end(), [](const student& x, const student& y) {
        if (x.score != y.score) return x.score > y.score;
        return x.id < y.id;
    });
    
    for (int i = 0; i < n; ++i) 
    {
        if (a[i].id == 1) {
            cout << i + 1 << endl;
            break;
        }
}
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

