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


void solve()
{   
    int n , m ;
    cin >> n >> m ;
    
    vector<int> dirty(m);
    for (auto &d : dirty) 
        cin >> d;
    if (n == 1) {
        for (int d : dirty) {
            if (d == 1 ) {
                cout << "NO";
                return ;
            }
        }
        cout << "YES";
        return ;
    }
    
    sort(dirty.begin(), dirty.end());
    
    for (auto d : dirty) {
        if (d == 1 || d == n) {
            cout << "NO";
            return ;
        }
    }
    for (int i = 0; i + 2 < m; i++) 
    {
        if (dirty[i+1] == dirty[i] + 1 && dirty[i+2] == dirty[i] + 2) {
            cout << "NO";
            return ;
        }
    }
    cout << "YES";
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

