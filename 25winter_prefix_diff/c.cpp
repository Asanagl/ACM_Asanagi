#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
const int INF = 1e6;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;


vector<bool> izayoi(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}
void solve()
{
    int n ;
    cin >> n ;
    vector<bool> prime = izayoi(INF);
    vector<int> a(n) ;
    for (auto &it : a ) cin >> it ;
    vector <int> prefix (n+1) ;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + (prime[a[i - 1]]? 1 : 0);
    }
    int q ;
    cin >> q ;
    while (q--) {
        int l , r ;
        cin >> l >> r ;
        cout << prefix[r] - prefix[l - 1] << endl;
    }

}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}