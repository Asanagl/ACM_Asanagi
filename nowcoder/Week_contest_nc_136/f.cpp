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
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void solve()
{
    int n , k ;
    cin >> n >> k ;
    if (n == 1) {
        if (k == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return ;
    }
    int maxe = 0;
    for (int r = 1; r * r <= n; ++r) {
        int c = (n + r - 1) / r;
        int rowman = n / c;
        int rem = n % c;
        int edges = rowman * (c - 1) + (rowman - 1) * c; 
        if (rem > 0) {
            edges += (rem - 1); 
            edges += rowman; 
        }
        maxe = max(maxe, edges);
    }
    if (k > maxe) {
        cout << "No" <<endl;
        return ;
    }
    cout << "Yes" << endl;
    
    if (k < n) {
        for (int i = 0; i <= k; ++i) {
            cout << i << " 0" << endl;
        }
        for (int i = 0; i < n - k - 1; ++i) {
            cout << (i * 2) << " 3" << endl;
        }
        return ;
    }
    for (int r = 2; r <= n; ++r) {
        int c = (n + r - 1) / r;
        if (c < 1) continue;
        int roman = n / c;
        int cnt = n % c;
        int basee = 0;
        basee += roman * (c - 1);
        if (cnt > 0) basee += (cnt - 1);
        basee += (roman - 1) * c;
        if (cnt > 0) basee += cnt;
        if (basee < k) continue;
        vector<pair<int, int>> points;
        int det = basee - k; 
        int cnx = 0;
        for (int i = 0; i < r; ++i) {
            int cnr = (i < roman) ? c : (i == roman ? cnt : 0);
            if (cnr == 0) break;
            for (int j = 0; j < cnr; ++j) {
                if (j == 0) {
                    points.pb({cnx, i});
                } else {
                    if (det > 0) {
                        cnx += 2;
                        det--;
                    } else {
                        cnx += 1;
                    }
                    points.pb({cnx, i});
                }
            }
            cnx = 0;
        }
        
        for (auto &[x, y] : points) {
            cout << x << " " << y << endl;
        }
        return ;
    }
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}




