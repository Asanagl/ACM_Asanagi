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

void Asanagi()
{
    int n ;
    cin >> n ;
    vector <int> vi (n);
    for (auto &it : vi ) cin >> it ;
    if (vi[0] == vi[n - 1]) 
    {
            cout << "NO" << endl;
    } else {
            cout << "YES" << endl;
            cout << vi[n - 1] << " ";
            for (int i = 0; i < n - 1; i++) {
                cout << vi[i];
                if (i < n - 2) cout << " ";
            }
            cout << endl;}
}

signed main()
{
    IOS;
    int t ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}